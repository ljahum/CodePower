positive_feedback = ["smart","brilliant","studious"]
negative_feedback = ["not"]
report = ["this student is not studious","the student is smart"]
student_id = [1,2]
k = 2


words = {}
for pf in positive_feedback:
    words[pf] = 3


for pf in negative_feedback:
    words[pf] = -1

arr = []
for s, id in zip(report,student_id):
    tmp = s.split()
    # print(tmp)
    vaild_words = [words.get(w, 0) for w  in tmp]
    # print(vaild_words)
    score  = sum(vaild_words)
    arr.append([-score,id])
arr.sort()
arr = arr[:k]
# print(arr)
ans = [i[1] for i in arr]
print(ans)
