try
{
    OpenFile(strFilename);
    WriteFile(strFilename, strData);
    CloseFile(strFilename);
}
catch (FileException &cException)
{
    // Make sure file is closed
    CloseFile(strFilename);
    // Then write error
    cerr << "Failed to write to file: " << cException.what() << endl;
}