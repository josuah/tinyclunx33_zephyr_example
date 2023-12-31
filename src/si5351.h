#pragma once

#define SI5351_I2C_ADDR 0x60

static struct config { uint8_t addr, data; } si5351_config[] = {
	{ 0x02, 0x53, },
	{ 0x03, 0x00, },
	{ 0x04, 0x20, },
	{ 0x07, 0x04, },
	{ 0x0F, 0x00, },
	{ 0x10, 0x8C, },
	{ 0x11, 0x0F, },
	{ 0x12, 0x0F, },
	{ 0x13, 0x8C, },
	{ 0x14, 0x8C, },
	{ 0x15, 0x8C, },
	{ 0x16, 0x8C, },
	{ 0x17, 0x8C, },
	{ 0x1A, 0x00, },
	{ 0x1B, 0x01, },
	{ 0x1C, 0x00, },
	{ 0x1D, 0x10, },
	{ 0x1E, 0x00, },
	{ 0x1F, 0x00, },
	{ 0x32, 0x00, },
	{ 0x33, 0x01, },
	{ 0x34, 0x00, },
	{ 0x35, 0x05, },
	{ 0x36, 0x80, },
	{ 0x37, 0x00, },
	{ 0x38, 0x00, },
	{ 0x39, 0x00, },
	{ 0x3A, 0x00, },
	{ 0x3B, 0x02, },
	{ 0x3C, 0x00, },
	{ 0x3D, 0x10, },
	{ 0x3E, 0xC0, },
	{ 0x3F, 0x00, },
	{ 0x40, 0x00, },
	{ 0x41, 0x00, },
	{ 0x5A, 0x00, },
	{ 0x5B, 0x00, },
	{ 0x95, 0x00, },
	{ 0x96, 0x00, },
	{ 0x97, 0x00, },
	{ 0x98, 0x00, },
	{ 0x99, 0x00, },
	{ 0x9A, 0x00, },
	{ 0x9B, 0x00, },
	{ 0xA2, 0x00, },
	{ 0xA3, 0x00, },
	{ 0xA4, 0x00, },
	{ 0xA6, 0x00, },
	{ 0xA7, 0x00, },
	{ 0xB7, 0x92, },

	/* Keeping it at the top causes troubles. */
	{ 0x20, 0x00, },
	{ 0x21, 0x00, },
};

static void si5351_i2c_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t reg_data);

static void si5351_init(void)
{
	for (int i = 0; i < ARRAY_SIZE(si5351_config); i++) {
		si5351_i2c_write(SI5351_I2C_ADDR, si5351_config[i].addr,
				si5351_config[i].data);
	}
}
