std::ifstream fSetupIni("setup.ini"); // open setup.ini for reading
    if (!fSetupIni)
        return ERROR_OPENING_FILE; // Some enum value indicating error

    // Note that error handling and actual code logic are intermingled

    if (!ReadParameter(fSetupIni, m_nFirstParameter))
        return ERROR_PARAMETER_MISSING; // Some other enum value indicating error
    if (!ReadParameter(fSetupIni, m_nSecondParameter))
        return ERROR_PARAMETER_MISSING; // Some other enum value indicating error
    if (!ReadParameter(fSetupIni, m_nThirdParameter))
        return ERROR_PARAMETER_MISSING; // Some other enum value indicating error