#include <iostream>
#include <cmath>

using namespace std;

class point {
    friend class pointarr;  // 프렌드 클래스를 지정
private:
    float x, y; // 하나의 좌표 (x, y)
public:
    // 기본 생성자가 없을 경우 pointarr에서 동적 할당시 문제가 생김
    point() {
        this->x = 0;
        this->y = 0;
    }
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class pointarr {
private:
    point* arr; // point 배열, 동적으로 생성됨
    int n;  // arr 배열의 크기
public:
    pointarr(int n) {
        arr = new point[n];
        this->n = n;
    }

    // 좌표들 사이에서 가장 먼 거리를 반환
    float maxDist() {
        float max_dist = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                float x_dist = abs(arr[i].x - arr[j].x);
                float y_dist = abs(arr[i].y - arr[j].y);
                max_dist = max(max_dist, float(sqrt(pow(x_dist, 2) + pow(y_dist, 2))));
            }
        }

        return max_dist;
    }

    // 동적 할당된 배열에 포인트 객체 할당
    void setPoint(point p, int n) {
        arr[n] = p;
    }
};

int main() {
    point p1(1, 2), p2(2, 3), p3(3, 4), p4(5, 6);
    pointarr pa(4);

    pa.setPoint(p1, 0);
    pa.setPoint(p2, 1);
    pa.setPoint(p3, 2);
    pa.setPoint(p4, 3);
    cout << pa.maxDist();

    return 0;
}