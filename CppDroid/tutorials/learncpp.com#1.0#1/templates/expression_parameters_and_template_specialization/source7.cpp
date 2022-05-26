Storage<char*>::Storage(char* tValue)
{
    // Allocate memory to hold the tValue string
    m_tValue = new char[strlen(tValue)+1];
    // Copy the actual tValue string into the m_tValue memory we just allocated
    strcpy(m_tValue, tValue);
}