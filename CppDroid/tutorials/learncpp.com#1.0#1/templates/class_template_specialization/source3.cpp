template <> // the following is a template class with no templated parameters
class Storage8<bool> // we're specializing Storage8 for bool
{
// What follows is just standard class implementation details
private:
    unsigned char m_tType;

public:
    void Set(int nIndex, bool tType)
    {
        // Figure out which bit we're setting/unsetting
        // This will put a 1 in the bit we're interested in turning on/off
        unsigned char nMask = 1 << nIndex;

        if (tType)  // If we're setting a bit
            m_tType |= nMask;  // Use bitwise-or to turn that bit on
        else  // if we're turning a bit off
            m_tType &= ~nMask;  // bitwise-and the inverse mask to turn that bit off
	}

    bool Get(int nIndex)
    {
        // Figure out which bit we're getting
        unsigned char nMask = 1 << nIndex;
        // bitwise-and to get the value of the bit we're interested in
        // Then implicit cast to boolean
        return m_tType & nMask;
    }
};