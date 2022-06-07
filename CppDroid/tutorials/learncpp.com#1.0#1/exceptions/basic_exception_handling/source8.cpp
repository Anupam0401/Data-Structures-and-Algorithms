std::ifstream fSetupIni("setup.ini"); // open setup.ini for reading
    if (!fSetupIni)
        return ERROR_OPENING_FILE; // Some enum value indicating error

    // Read parameters and return an error if the parameter is missing
    try
    {
        // Here's all the normal code logic
        m_nFirstParameter = ReadParameter(fSetupIni);
        m_nSecondParameter = ReadParameter(fSetupIni);
        m_nThirdParameter = ReadParameter(fSetupIni);
    }
    catch (int) // Here's the error handling, nicely separated
    {
        return ERROR_PARAMETER_MISSING; // Some other enum value indicating error
    }