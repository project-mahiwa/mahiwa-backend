#include <lib/wasm-functions/network/network.hpp>
wifi_mode_t convertWiFiMode(int32_t mode)
{
    switch (mode)
    {
    case 0:
        return WIFI_OFF;
    case 1:
        return WIFI_STA;
    case 2:
        return WIFI_AP;
    case 3:
        return WIFI_AP_STA;
    default:
        // 正直これ以外がきたら，ちゃんと例外にして止めたい
        return WIFI_STA;
    }
}

m3ApiRawFunction(m3_wlanMode)
{
    m3ApiGetArg(int32_t, mode);

    // Serial.print("WIFI MODE:");
    // Serial.println(convertWiFiMode(mode));
    WiFi.mode(convertWiFiMode(mode));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_wlanConnect)
{
    m3ApiGetArgMem(const byte *, ssid);
    m3ApiGetArg(int32_t, ssidLen);
    m3ApiGetArgMem(const byte *, password);
    m3ApiGetArg(int32_t, passwordLen);

    byte lSsid[ssidLen + 1];
    byte lPassword[passwordLen + 1];

    memcpy(lSsid, ssid, ssidLen);
    lSsid[ssidLen] = '\0';
    memcpy(lPassword, password, passwordLen);
    lPassword[passwordLen] = '\0';

    // Serial.print("SSID:");
    // Serial.println((char *)lSsid);
    // Serial.print("PASS:");
    // Serial.println((char *)lPassword);
    WiFi.begin((char *)lSsid, (char *)lPassword);

    m3ApiSuccess();
}

m3ApiRawFunction(m3_wlanStatus)
{
    m3ApiReturnType(int32_t);

    m3ApiReturn(WiFi.status());

    m3ApiSuccess();
}

m3ApiRawFunction(m3_wlanLocalIp)
{
    m3ApiGetArgMem(char *, out);

    String ipString = WiFi.localIP().toString(); // 一旦代入してからc_strしないとスコープ的にまずくて壊れる
    const char *ipChar = ipString.c_str();
    uint32_t len = strlen(ipChar);
    memcpy(out, ipChar, len);
    out[len] = '\0';

    m3ApiSuccess();
}

M3Result mahiwa_LinkNetwork(IM3Runtime runtime)
{
    IM3Module modules = runtime->modules;
    const char *module = "network";

    m3_LinkRawFunction(modules, module, "wlanMode", "v(i)", &m3_wlanMode);
    m3_LinkRawFunction(modules, module, "wlanConnect", "v(*i*i)", &m3_wlanConnect);
    m3_LinkRawFunction(modules, module, "wlanStatus", "i()", &m3_wlanStatus);
    m3_LinkRawFunction(modules, module, "wlanLocalIp", "v(*)", &m3_wlanLocalIp);

    return m3Err_none;
}
