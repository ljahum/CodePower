//
// created by ljahum on 2023-03-03 16:25:30
//
#include <stdio.h>
#include <pthread.h>

#define EVEN 0
#define ODD 1
#include <stdbool.h>
int count = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;
//加入条件变量避免出现 "申请了但是不用" 导致的资源浪费问题
bool flag = true;
void* run1(void* data) {
    bool myflag = true;//1号线程先运行
    for ( int i = 1; i <= 10; i+=2)
    {
		pthread_mutex_lock(&mutex);
		while(myflag !=flag){
			pthread_cond_signal(&cond);
			// 通知另一个线程处理，避免出现死锁
			pthread_cond_wait(&cond,&mutex);
			// 阻塞，直到收另外一个进程信号并且得到互斥锁
		}
		printf("%d ",i);
		if(i-count!=1){
			printf("error\n");
			pthread_exit(1);
		}
		count++;
		flag =( !flag);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
    }    
  return;
}
void* run2(void* data) {
    bool myflag =false;//false 2号线程后运行
    for ( int i = 2; i <= 10; i+=2)
    {
		pthread_mutex_lock(&mutex);
		while(myflag !=flag){
			pthread_cond_signal(&cond);
			// 通知另一个线程处理，避免出现死锁
			pthread_cond_wait(&cond,&mutex);
			// 阻塞，直到收另外一个进程信号并且得到互斥锁
		}
		printf("%d ",i);
		if(i-count!=1){
			printf("error\n");
			pthread_exit(1);
		}
		count++;
		flag =( !flag);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
    }    
  return;
}


int main(int c, char** v) {
	pthread_t tid1, tid2;
	pthread_mutex_init(&mutex, NULL); // 初始化mutex
	pthread_create(&tid1, NULL, run1, ODD);
	pthread_create(&tid2, NULL, run2, EVEN);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&mutex); // 回收 mutex
	printf("\ncount is %d\n", count); // count is 2000000
}
