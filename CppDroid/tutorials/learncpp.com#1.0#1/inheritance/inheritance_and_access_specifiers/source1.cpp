class Base
{
private:
    int m_nPrivate; // can only be accessed by Base member functions (not derived classes)
public:
    int m_nPublic; // can be accessed by anybody
};