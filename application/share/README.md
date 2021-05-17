# Share Folder `[DATADIR]`
In this folder you should put all the files that your application needs.
> e.g. icons, media, text data...

At the time of construction this folder will be copied to **${CMAKE_BINARY_DIR}/share**
> e.g. build/share

At installation time and at the time of installation it will be copied to **${CMAKE_INSTALL_DATADIR}**
> e.g. /usr/local/${CMAKE_PROJECT_NAME}/share
