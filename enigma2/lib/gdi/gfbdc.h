#ifndef __gfbdc_h
#define __gfbdc_h

#include "fb.h"
#include "gpixmap.h"
#include "gmaindc.h"

class gFBDC: public gMainDC
{
	fbClass *fb;
	void exec(const gOpcode *opcode);
	unsigned char ramp[256], rampalpha[256]; // RGB ramp 0..255
	int brightness, gamma, alpha;
	void calcRamp();
	void setPalette();
	gUnmanagedSurface surface;
	gUnmanagedSurface surface_back;
public:
	void setResolution(int xres, int yres, int bpp = 32);
	void reloadSettings();
	void setAlpha(int alpha);
	void setBrightness(int brightness);
	void setGamma(int gamma);

	int getAlpha() const { return alpha; }
	int getBrightness() const { return brightness; }
	int getGamma() const { return gamma; }

	int haveDoubleBuffering() const { return surface_back.data_phys != 0; }

	void saveSettings();

	gFBDC();
	virtual ~gFBDC();
	int islocked() const { return fb->islocked(); }
};

#endif
