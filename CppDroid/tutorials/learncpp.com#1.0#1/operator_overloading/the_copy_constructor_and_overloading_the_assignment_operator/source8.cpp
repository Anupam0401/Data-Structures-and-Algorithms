Cents& Cents::operator= (const Cents &cSource)
{
    // check for self-assignment by comparing the address of the
    // implicit object and the parameter
    if (this == &cSource)
        return *this;

    // do the copy
    m_nCents = cSource.m_nCents;

    // return the existing object
    return *this;
}