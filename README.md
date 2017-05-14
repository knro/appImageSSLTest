This is a simple SSL test for Qt 5.8+ in AppImages.

The test request this URL:

https://www.faa.gov/air_traffic/flight_info/aeronav/digital_products/dtpp/search/results/?cycle=1705&ident=KSAN

However, returned size is 0 if the application is ran within an AppImage. When running against Qt 5.8 in 16.04 locally, it works and downloads OK.

When running locally using Qt 5.8 under /opt, the SSL download fails like the AppImage under Ubuntu 14.04.

