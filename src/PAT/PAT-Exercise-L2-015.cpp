/**
 * Created by LonelyEnvoy on 2017-3-13.
 * L2-015. 互评成绩
 * Keywords: 优先级队列的简单应用
 */

#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main() {
    priority_queue<float> allStudentScores;
    priority_queue<int> singleStudentScores;
    stack<float> reversedOutputScores;

    int N;
    int k;
    int M;
    int data;
    int sum;

    scanf("%d%d%d", &N, &k, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &data);
            singleStudentScores.push(data);
        }

        // parse
        singleStudentScores.pop(); // ignore the max score
        sum = 0; // reset sum
        while (singleStudentScores.size() > 1) {
            sum += singleStudentScores.top();
            singleStudentScores.pop();
        }
        singleStudentScores.pop(); // ignore the min score
        // push the average score into queue
        allStudentScores.push((float)sum / (k - 2));
    }

    // get the score of top M students and reverse it to ascending order
    for (int i = 0; i < M; i++) {
        reversedOutputScores.push(allStudentScores.top());
        allStudentScores.pop();
    }
    // output the top M students' scores
    while (reversedOutputScores.size() > 1) {
        printf("%.3f ", reversedOutputScores.top());
        reversedOutputScores.pop();
    }
    // don't output a space for the last element
    printf("%.3f\n", reversedOutputScores.top());
}
