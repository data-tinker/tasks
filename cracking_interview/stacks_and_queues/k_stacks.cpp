#include <iostream>
#include <vector>

using namespace std;

class KStacks {
public:
    KStacks(size_t arraySize, size_t stacksCount)
        : Data(arraySize)
        , Top(stacksCount, -1)
        , Next(arraySize)
    {
        for (size_t i = 0; i < arraySize; ++i) {
            Next[i] = i + 1;
        }

        Next[arraySize - 1] = -1;
    }

    void Push(size_t stackIdx, int data);

    int Pop(size_t stackIdx);

    bool IsFull() {
        return FreeIdx == -1;
    }

    bool IsEmpty(size_t stackIdx) {
        return Top[stackIdx] == -1;
    }

private:
    vector<int> Data;
    vector<int> Top;
    vector<int> Next;
    int FreeIdx = 0;
};

void KStacks::Push(size_t stackIdx, int data) {
    if (IsFull()) {
        cout << "Stack overflow" << endl;
        return;
    }

    auto idx = FreeIdx;
    FreeIdx = Next[idx];

    Next[idx] = Top[stackIdx];
    Top[stackIdx] = idx;

    Data[idx] = data;
}

int KStacks::Pop(size_t stackIdx) {
    if (IsEmpty(stackIdx)) {
        cout << "Stack empty" << endl;
        return 1;
    }

    auto idx = Top[stackIdx];
    Top[stackIdx] = Next[idx];

    Next[idx] = FreeIdx;
    FreeIdx = idx;

    return Data[idx];
}

int main() {
    KStacks s(100, 3);

    s.Push(0, 1);
    s.Push(1, 2);
    s.Push(2, 3);
    s.Push(0, 4);

    cout << s.Pop(0) << endl;
    cout << s.Pop(1) << endl;
    cout << s.Pop(2) << endl;

    return 0;
}
