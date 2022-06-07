std::ifstream fSetupIni("setup.ini"); // open setup.ini for reading
    if (!fSetupIni)
        return ERROR_OPENING_FILE; // Some enum value indicating error

    // Read parameters and return an error if the parameter is missing
    if (!ReadParameter(fSetupIni, m_nFirstParameter))
        return ERROR_PARAMETER_MISSING; // Some other enum value indicating error
    if (!ReadParameter(fSetupIni, m_nSecondParameter))
        return ERROR_PARAMETER_MISSING; // Some other enum value indicating error
    if (!ReadParameter(fSetupIni, m_nThirdParameter))
        return ERROR_PARAMETER_MISSING; // Some other enum value indicating error