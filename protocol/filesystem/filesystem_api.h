#ifndef FAMP_filesystem_api
#define FAMP_filesystem_api

#pragma pack(1)
typedef struct ph
{
    /* Signify the start of partition header. */
    uint8            header_start[6]; // "PARTS  ", in binary: "P A R T S 00"

    /* Partition type(available to user, not available to user/available 
     * to user AND the kernel etc). 
     */
    uint8            partition_type;

    /* LBA values where partition starts/ends. */
    uint32           starting_LBA;
    uint32           ending_LBA;

    /* Address of partition(really, address of FS). */
    uint16           partition_address;

    /* Virtual address of partition. */
    uint32           virtual_address;

    /* What type of FS does the user want? FAMPs custom FS, or a pre-existing one? */
    uint8            FS_type;

    /* If `FS_type` is `FS_FAMP_custom` then what revision of FAMPs custom FS is currently being used? 
     * Set to zero if we are using a FS other than FAMPs custom FS. 
     */
    uint32           FAMP_custom_FS_revision;

    /* CHS(Cylinder, Head, Sector). Just in case we ever do need it.
     * A later revision of `struct PartitionHeader` will, more than likely, remove support for CHS.
     */
    uint16           cylinder;
    uint8            head;
    uint32           sector;

    /* 9 of the 15 bytes will be padded out with zero, 
     * the last 6 bytes will represent `PARTE  `, in binary: `P A R T E 00`(indicating the end of the partition header). 
     */
    uint8            header_end[15];
} _ph;
#pragma pop

#endif