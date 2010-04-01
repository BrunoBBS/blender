/**
 * blenlib/DNA_lamp_types.h (mar-2001 nzc)
 *
 * $Id$ 
 *
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */
#ifndef DNA_LAMP_TYPES_H
#define DNA_LAMP_TYPES_H

#include "DNA_ID.h"

#ifndef MAX_MTEX
#define MAX_MTEX	18
#endif

struct MTex;
struct CurveMapping;
struct AnimData;
struct Ipo;

typedef struct Lamp {
	ID id;
	struct AnimData *adt;	/* animation data (must be immediately after id for utilities to use it) */ 
	
	short type, flag;
	int mode;
	
	/* color and power */
	short colormodel, totex;
	float r, g, b, k;
	float shdwr, shdwg, shdwb;
	float energy, power;
	
	/* spots */
	float spotsize, spotblend, haint;
	short shadhalostep, pad6;
	
	/* falloff */
	struct CurveMapping *curfalloff;
	short falloff_type, pad2;
	float falloff_smooth, dist;
	
	/* shadow buffer */
	float clipsta, clipend, shadspotsize;
	float bias, soft, compressthresh, pad5;
	short bufsize, samp, buffers, filtertype;
	char bufflag, buftype;
	
	/* ray traced shadows */
	short ray_samp;
	short ray_samp_type;
	short area_shape;
	float area_size, area_sizey;
	float adapt_thresh;
	short ray_samp_method;
	short pad1;
	
	/* sun/sky */
	short sun_effect_type;
	short skyblendtype;
	float horizon_brightness;
	float spread;
	float sun_brightness;
	float sun_size;
	float backscattered_light;
	float sun_intensity;
	float atm_turbidity;
	float atm_inscattering_factor;
	float atm_extinction_factor;
	float atm_distance_factor;
	float skyblendfac;
	float sky_exposure;
	short sky_colorspace, pad4;

	struct Ipo *ipo;				// XXX depreceated... old animation system

	/* textures */
	struct MTex *mtex[18];			/* MAX_MTEX */
	short pr_texture, texact, pad[2];
	
	/* preview */
	struct PreviewImage *preview;
} Lamp;

/* **************** LAMP ********************* */

/* flag */
#define LA_DS_EXPAND	1
	/* NOTE: this must have the same value as MA_DS_SHOW_TEXS, 
	 * otherwise anim-editors will not read correctly
	 */
#define LA_DS_SHOW_TEXS	4

/* type */
#define LA_LOCAL		0
#define LA_SUN			1
#define LA_SPOT			2
#define LA_HEMI			3
#define LA_AREA			4
#define LA_DEPRECATED	5

/* mode */
#define LA_SHAD_BUF		1
#define LA_HALO			2
#define LA_LAYER		4
#define LA_QUAD			8	/* no longer used */
#define LA_NEG			16
#define LA_ONLYSHADOW	32
#define LA_SPHERE		64
#define LA_SQUARE		128
#define LA_TEXTURE		256
#define LA_OSATEX		512
/* #define LA_DEEP_SHADOW	1024 */ /* not used anywhere */
#define LA_NO_DIFF		2048
#define LA_NO_SPEC		4096
#define LA_SHAD_RAY		8192
/* yafray: lamp shadowbuffer flag, softlight */
/* Since it is used with LOCAL lamp, can't use LA_SHAD */
#define LA_YF_SOFT		16384
#define LA_LAYER_SHADOW	32768
#define LA_SHAD_TEX     (1<<16)
#define LA_SHOW_CONE    (1<<17)
#define LA_MULTI_SHADE  (1<<18)
#define LA_NO_INDIRECT	(1<<19)

/* layer_shadow */
#define LA_LAYER_SHADOW_BOTH	0
#define LA_LAYER_SHADOW_CAST	1
#define LA_LAYER_SHADOW_RECEIVE	2

/* sun effect type*/
#define LA_SUN_EFFECT_SKY			1
#define LA_SUN_EFFECT_AP			2

/* falloff_type */
#define LA_FALLOFF_CONSTANT		0
#define LA_FALLOFF_INVLINEAR	1
#define LA_FALLOFF_INVSQUARE	2
#define LA_FALLOFF_CURVE		3
#define LA_FALLOFF_SLIDERS		4	/* deprecated */

/* buftype, no flag */
#define LA_SHADBUF_REGULAR		0
#define LA_SHADBUF_IRREGULAR	1
#define LA_SHADBUF_HALFWAY		2
#define LA_SHADBUF_DEEP			3

/* bufflag, auto clipping */
#define LA_SHADBUF_AUTO_START	1
#define LA_SHADBUF_AUTO_END		2
#define LA_SHADBUF_NO_STRANDS	4

/* filtertype */
#define LA_SHADBUF_BOX		0
#define LA_SHADBUF_TENT		1
#define LA_SHADBUF_GAUSS	2

/* area shape */
#define LA_AREA_SQUARE	0
#define LA_AREA_RECT	1
#define LA_AREA_CUBE	2
#define LA_AREA_BOX		3

/* ray_samp_method */
#define LA_SAMP_CONSTANT	0	/* deprecated */
#define LA_SAMP_HALTON		1
#define LA_SAMP_HAMMERSLEY	2

/* ray_samp_type */
#define LA_SAMP_ROUND	1	/* deprecated */
#define LA_SAMP_UMBRA	2	/* deprecated */
#define LA_SAMP_DITHER	4	/* deprecated */
#define LA_SAMP_JITTER	8	/* deprecated */

/* mapto */
#define LAMAP_COL		1
#define LAMAP_SHAD		2


#endif /* DNA_LAMP_TYPES_H */

