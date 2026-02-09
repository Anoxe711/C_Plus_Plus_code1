#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int x1A, y1A, x2A, y2A;
    cout << "Введите прямоугольник A: ";
    cin >> x1A >> y1A >> x2A >> y2A;
  
    int x1B, y1B, x2B, y2B;
    cout << "Введите прямоугольник B: ";
    cin >> x1B >> y1B >> x2B >> y2B;

    int minXA = min(x1A, x2A);
    int maxXA = max(x1A, x2A);
    int minYA = min(y1A, y2A);
    int maxYA = max(y1A, y2A);

    int minXB = min(x1B, x2B);
    int maxXB = max(x1B, x2B);
    int minYB = min(y1B, y2B);
    int maxYB = max(y1B, y2B);

    // Создаем множества точек
    set<pair<int, int>> pointsA;
    set<pair<int, int>> pointsB;

    // Заполняем множество A
    for (int x = minXA; x <= maxXA; x++) {
        for (int y = minYA; y <= maxYA; y++) {
            pointsA.insert({ x, y });
        }
    }

    // Заполняем множество B
    for (int x = minXB; x <= maxXB; x++) {
        for (int y = minYB; y <= maxYB; y++) {
            pointsB.insert({ x, y });
        }
    }

    // Находим пересечение множеств с помощью set_intersection
    set<pair<int, int>> commonPoints;

    // Используем алгоритм set_intersection для нахождения пересечения
    set_intersection(
        pointsA.begin(), pointsA.end(),
        pointsB.begin(), pointsB.end(),
        inserter(commonPoints, commonPoints.begin())
    );

    // Выводим результат
    cout << "\nРезультат:" << endl;
    cout << "Прямоугольник A: [" << minXA << "," << minYA << "]-["
        << maxXA << "," << maxYA << "]" << endl;
    cout << "Точек в A: " << pointsA.size() << endl;

    cout << "Прямоугольник B: [" << minXB << "," << minYB << "]-["
        << maxXB << "," << maxYB << "]" << endl;
    cout << "Точек в B: " << pointsB.size() << endl;

    if (!commonPoints.empty()) {
        cout << "\nПрямоугольники ПЕРЕСЕКАЮТСЯ" << endl;
        cout << "Общих точек: " << commonPoints.size() << endl;
        cout << "Общие точки: ";

        int count = 0;
        for (const auto& point : commonPoints) {
            cout << "(" << point.first << "," << point.second << ")";
            if (++count < commonPoints.size()) cout << ", ";
            if (count % 5 == 0) cout << endl << "                ";
        }
        cout << endl;
    }
    else {
        cout << "\nПрямоугольники НЕ пересекаются" << endl;
    }

    return 0;
}
