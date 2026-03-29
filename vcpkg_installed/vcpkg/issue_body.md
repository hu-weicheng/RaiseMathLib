Package: intel-mkl:x64-windows@2023.0.0#3

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.50.35728.0
- CMake Version: 4.2.3-msvc3
-    vcpkg-tool version: 2025-12-16-44bb3ce006467fc13ba37ca099f64077b8bbf84d
    vcpkg-readonly: true
    vcpkg-scripts version: 544a4c5c297e60e4ac4a5a1810df66748d908869

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached lessmsi-v1.10.0.zip
-- Using cached w_onemkl_p_2023.0.0.25930_offline.exe
Downloading https://github.com/ip7z/7zip/releases/download/24.09/7z2409.exe -> 7z2409.7z.exe
warning: Download https://github.com/ip7z/7zip/releases/download/24.09/7z2409.exe failed -- retrying after 1000ms
warning: Download https://github.com/ip7z/7zip/releases/download/24.09/7z2409.exe failed -- retrying after 2000ms
warning: Download https://github.com/ip7z/7zip/releases/download/24.09/7z2409.exe failed -- retrying after 4000ms
error: https://github.com/ip7z/7zip/releases/download/24.09/7z2409.exe: WinHttpSendRequest failed with exit code 12002. 操作超时
note: If you are using a proxy, please ensure your proxy settings are correct.
Possible causes are:
1. You are actually using an HTTP proxy, but setting HTTPS_PROXY variable to `https://address:port`.
This is not correct, because `https://` prefix claims the proxy is an HTTPS proxy, while your proxy (v2ray, shadowsocksr, etc...) is an HTTP proxy.
Try setting `http://address:port` to both HTTP_PROXY and HTTPS_PROXY instead.
2. If you are using Windows, vcpkg will automatically use your Windows IE Proxy Settings set by your proxy software. See: https://github.com/microsoft/vcpkg-tool/pull/77
The value set by your proxy might be wrong, or have same `https://` prefix issue.
3. Your proxy's remote server is out of service.
If you believe this is not a temporary download server failure and vcpkg needs to be changed to download this file from a different location, please submit an issue to https://github.com/Microsoft/vcpkg/issues
CMake Error at scripts/cmake/vcpkg_download_distfile.cmake:136 (message):
  Download failed, halting portfile.
Call Stack (most recent call first):
  scripts/cmake/vcpkg_find_acquire_program.cmake:183 (vcpkg_download_distfile)
  C:/Users/Rise8/AppData/Local/vcpkg/registries/git-trees/3dd3ebb16924351eed10c170704517f54a72f274/portfile.cmake:74 (vcpkg_find_acquire_program)
  scripts/ports.cmake:206 (include)



```

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "arrayfire"
  ],
  "builtin-baseline": "bb588985e37484d543fc849d0d79434e0d45bb3c"
}

```
</details>
