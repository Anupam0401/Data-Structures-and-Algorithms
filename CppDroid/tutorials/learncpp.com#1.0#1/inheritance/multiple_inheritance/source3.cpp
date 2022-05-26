int main()
{
    WirelessAdaptor c54G(5442, 181742);
    cout << c54G.USBDevice::GetID();

    return 0;
}