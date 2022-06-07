class MyStruct
{
private:
    int m_nX;
    float m_nY;

public:
    MyStruct(int x, float y): m_nX(x), m_nY(y) {};
};

MyStruct foo {2, 3.5f};