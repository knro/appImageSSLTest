[![Build Status](https://travis-ci.org/knro/appImageSSLTest?branch=master)](https://travis-ci.org/knro/appImageSSLTest)

This is a simple SSL test for Qt 5.8+ in AppImages.

The test request this URL:

https://www.faa.gov/air_traffic/flight_info/aeronav/digital_products/dtpp/search/results/?cycle=1705&ident=KSAN

However, returned size is 0 if the application is ran within an AppImage.

16.04: Compiled against Qt 5.8, it works and downloads OK **locally**. With AppImage, it fails.

14.04: Compilted against Qt 5.8, it fails **locall** as well as within an AppImage.

