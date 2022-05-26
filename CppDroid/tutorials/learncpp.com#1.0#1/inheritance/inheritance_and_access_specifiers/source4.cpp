class Base
{
public:
    int m_nPublic;
private:
    int m_nPrivate;
protected:
    int m_nProtected;
};

class Pub: public Base
{
    // Public inheritance means:
    // m_nPublic stays public
    // m_nPrivate stays private
    // m_nProtected stays protected

    Pub()
    {
        // The derived class always uses the immediate parent's class access specifications
        // Thus, Pub uses Base's access specifiers
        m_nPublic = 1; // okay: anybody can access public members
        m_nPrivate = 2; // not okay: derived classes can't access private members in the base class!
        m_nProtected = 3; // okay: derived classes can access protected members
    }
};

int main()
{
    // Outside access uses the access specifiers of the class being accessed.
    // In this case, the access specifiers of cPub.  Because Pub has inherited publicly from Base,
    // no access specifiers have been changed.
    Pub cPub;
    cPub.m_nPublic = 1; // okay: anybody can access public members
    cPub.m_nPrivate = 2; // not okay: can not access private members from outside class
    cPub.m_nProtected = 3; // not okay: can not access protected members from outside class
}