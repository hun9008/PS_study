# 정수 삼각형 실버1
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.
# 문제 풀이
- dp문제
- 이전 RGB문제와 유사하나 입력받는 행이 1~n까지 다르다.
- i열의 dp값은 이전 dp[i], dp[i-1]중 최대 + input[i]를 하면 되나,
- 삼각형 각 행의 첫 열과 마지막 열은 바로 위의 값에서만 올 수 있으므로 예외처리 해준다.

# 총평
- 삼각형 형태로 생기는 예외만 처리하면 쉬운 DP문제
- dp문제임을 쉽게 알 수 있다.