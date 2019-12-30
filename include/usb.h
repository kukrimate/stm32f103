#ifndef USB_H
#define USB_H

struct usb
{
	uint32_t EP0R;
	uint32_t EP1R;
	uint32_t EP2R;
	uint32_t EP3R;
	uint32_t EP4R;
	uint32_t EP5R;
	uint32_t EP6R;
	uint32_t EP7R;
	uint8_t reserved[32];
	uint32_t CNTR;
	uint32_t ISTR;
	uint32_t FNR;
	uint32_t DADDR;
	uint32_t BTABLE;
} __attribute__((packed));

#define USB ((struct usb *) (0x40005c00))

#define CNTR_PWDN (1 << 1)
#define CNTR_FRES (1 << 0)

#endif
