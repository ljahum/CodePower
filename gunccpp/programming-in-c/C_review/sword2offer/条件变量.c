// thread-mutex.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

int count = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;
bool flag = true;

void* even_thread(void* data) {
  bool should_this_thread_handle_odd = (bool)data; // 根据参数决定此线程是处理奇数还是偶数
  int i = should_this_thread_handle_odd ? 1 : 2; // 奇数从1开始处理，偶数从0开始处理
  while (i <= 10000) {
    pthread_mutex_lock(&mutex);
    while (should_this_thread_handle_odd != flag) { // 判断是否该本线程处理
      pthread_cond_signal(&cond); // 通知另一个线程处理，避免出现死锁
      pthread_cond_wait(&cond, &mutex); // 阻塞，直到收到信号并且得到互斥锁
    }
    if (i - count != 1) { // 判断线程是否是交替执行的
      printf("error\n");
      exit(1);
    }
    count++;
    flag = !flag;
    pthread_cond_signal(&cond); // 通知另一个线程处理
    pthread_mutex_unlock(&mutex);
    i += 2;
  }
  return NULL;
}

int main() {
  pthread_t tid1, tid2;
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);
  // id null thread 传入thread的参数
  pthread_create(&tid1, NULL, even_thread, (void*)true);
  pthread_create(&tid2, NULL, even_thread, (void*)false);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  printf("%d\n", count); // 10000
}
