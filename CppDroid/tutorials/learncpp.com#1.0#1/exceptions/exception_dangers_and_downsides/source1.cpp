try
{
    OpenFile(strFilename);
    WriteFile(strFilename, strData);
    CloseFile(strFilename);
}
catch (FileException &cException)
{
    cerr << "Failed to write to file: " << cException.what() << endl;
}