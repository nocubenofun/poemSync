#define POEMSYNC_VERSION "0.0.1" //Unrecommented to change!!!
#define BUILD_VERSION "undefined" //Please change before building.
#define MCONFIG_FILE "/etc/poemSync.ini" //Main config file's path. Set to "_REMOTE_" if remote syncing is enabled.
#define RELEASE //Delete this line if this build need to show debug messages.
/* These are for remote syncing, enable them if you need:
 * #define REMOTE //Setup network at the first time.
 * #define ROOT_ON_FTP //Use curl-ftpfs as rootfs. !THIS NEED CONFIG!
 * #define ROFTP_CONFIG_FILE "/etc/poemSync-ftp.ini" //FTP Root's config file.
 * #define SSH_ON_STARTUP //SSH on startup
 * #define SSHOS_CONFIG_FILE "/etc/poemSync-ssh.ini" //SSH on Startup's config file */
