# 오르막수 실버1
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.

# 문제 풀이
- 자리수 별로 생각해보았다.
- 최고자리수의 수가 커질수록 가능한 경우의 수가 일정히 줄었다.
- ex

| 최고자리수 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1자리는 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 2자리는 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 |
| 3자리는 | 55 | 45 | 36 | 28 | 21 | 15 | 10 | 6 | 3 | 1 |

- dp[i] 는 이전dp[i]~dp[9]까지의 합임을 알 수 있었다.

# 총평
- 10007로 나눈 나머지를 저장하는데 dp를 만들때 수행해주고,
- 마지막 답을 낼때, dp[0]~dp[9]까지의 합을 한 후에도 수행해주어야 한다.