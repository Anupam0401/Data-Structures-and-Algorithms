Storage<char*>::~Storage()
{
    delete[] m_tValue;
}