﻿/*
===========================================================================
    Copyright (C) 1999-2005 Id Software, Inc.

    This file is part of CoD4X18-Server source code.

    CoD4X18-Server source code is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CoD4X18-Server source code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
===========================================================================
*/

#pragma once

/*
==============================================================

MATHLIB

==============================================================
*/

using byte = unsigned char;

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec5_t[5];

typedef int fixed4_t;
typedef int fixed8_t;
typedef int fixed16_t;

#include "qshared.hpp"

extern vec4_t colorBlack;

extern vec4_t colorMdRed;
extern vec4_t colorDkRed;

extern vec4_t colorMdGreen;
extern vec4_t colorDkGreen;

extern vec4_t colorLtBlue;
extern vec4_t colorMdBlue;

extern vec4_t colorDkYellow;
extern vec4_t colorMdYellow;
extern vec4_t colorLtYellow;

extern vec4_t colorMagenta;

extern vec4_t colorLtCyan;
extern vec4_t colorMdCyan;
extern vec4_t colorDkCyan;

extern vec4_t colorMdGrey;
extern vec4_t colorDkGrey;

extern vec4_t colorLtOrange;

extern vec4_t colorGreenFaded;
extern vec4_t colorBlackBlank;


#define DotProduct(a,b)         ((a)[0]*(b)[0]+(a)[1]*(b)[1]+(a)[2]*(b)[2])
#define VectorSubtract(a,b,c)   ((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define VectorAdd(a,b,c)        ((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorCopy(a,b)         ((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])

#define	VectorScale(v, s, o)    ((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define	Vec2Scale(v, s, o)    ((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s))
#define VectorMA(v, s, b, o)    ((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))
#define CrossProduct(a,b,c)     ((c)[0]=(a)[1]*(b)[2]-(a)[2]*(b)[1],(c)[1]=(a)[2]*(b)[0]-(a)[0]*(b)[2],(c)[2]=(a)[0]*(b)[1]-(a)[1]*(b)[0])

#define DotProduct4( x,y )        ( ( x )[0] * ( y )[0] + ( x )[1] * ( y )[1] + ( x )[2] * ( y )[2] + ( x )[3] * ( y )[3] )
#define VectorSubtract4( a,b,c )  ( ( c )[0] = ( a )[0] - ( b )[0],( c )[1] = ( a )[1] - ( b )[1],( c )[2] = ( a )[2] - ( b )[2],( c )[3] = ( a )[3] - ( b )[3] )
#define VectorAdd4( a,b,c )       ( ( c )[0] = ( a )[0] + ( b )[0],( c )[1] = ( a )[1] + ( b )[1],( c )[2] = ( a )[2] + ( b )[2],( c )[3] = ( a )[3] + ( b )[3] )
#define VectorCopy4( a,b )        ( ( b )[0] = ( a )[0],( b )[1] = ( a )[1],( b )[2] = ( a )[2],( b )[3] = ( a )[3] )
#define VectorScale4( v, s, o )   ( ( o )[0] = ( v )[0] * ( s ),( o )[1] = ( v )[1] * ( s ),( o )[2] = ( v )[2] * ( s ),( o )[3] = ( v )[3] * ( s ) )
#define VectorMA4( v, s, b, o )   ( ( o )[0] = ( v )[0] + ( b )[0] * ( s ),( o )[1] = ( v )[1] + ( b )[1] * ( s ),( o )[2] = ( v )[2] + ( b )[2] * ( s ),( o )[3] = ( v )[3] + ( b )[3] * ( s ) )


#define VectorClear(a)		((a)[0]=(a)[1]=(a)[2]=0)
#define VectorNegate( a,b )       ( ( b )[0] = -( a )[0],( b )[1] = -( a )[1],( b )[2] = -( a )[2] )
#define VectorNegate4( a,b )       ( ( b )[0] = -( a )[0],( b )[1] = -( a )[1],( b )[2] = -( a )[2],( b )[3] = -( a )[3] )
#define VectorSet(v, x, y, z)	((v)[0]=(x), (v)[1]=(y), (v)[2]=(z))
#define Vector4Copy( a,b )        ( ( b )[0] = ( a )[0],( b )[1] = ( a )[1],( b )[2] = ( a )[2],( b )[3] = ( a )[3] )

#define SnapVector( v ) {v[0] = (float)(signed int)v[0]; v[1] = (float)(signed int)v[1]; v[2] = (float)(signed int)v[2];}

#define VectorNormalize Vec3Normalize

/* Using 'vec*_t' types causes errors. */
#define vec2_copy(to, from) (to)[0] = (from)[0]; (to)[1] = (from)[1]
#define vec2_add(to, from) (to)[0] += (from)[0]; (to)[1] += (from)[1]
#define vec2_substract(to, from) (to)[0] -= (from)[0]; (to)[1] -= (from)[1]
#define vec2_multiply(v, k) (v)[0] *= (k); (v)[1] *= (k)
#define vec2_length(v) sqrtf((v)[0]*(v)[0] + (v)[1]*(v)[1])
#define vec2_floor(v) (v)[0] = floorf((v)[0]); (v)[1] = floorf((v)[1])
#define vec2_rotate(v, pitch) \
    do { \
        vec2_t __cp; \
        vec2_copy(__cp, (v)); \
        float cosa = cosf(pitch*M_PI/180); /* In radians. */ \
        float sina = sinf(pitch*M_PI/180); /* In radians. */ \
        (v)[0] = __cp[0]*cosa - __cp[1]*sina; \
        (v)[1] = __cp[0]*sina + __cp[1]*cosa; \
    } while(0)


#define vec3_copy(to, from) vec2_copy((to), (from)); (to)[2] = (from)[2]
#define vec3_add(to, from) vec2_add((to), (from)); (to)[2] += (from)[2]
#define vec3_substract(to, from) vec2_substract((to), (from)); (to)[2] -= (from)[2]
#define vec3_multiply(v, k) vec2_multiply((v), (k)); (v)[2] *= (k)

#define Square( x ) ( ( x ) * ( x ) )



#ifndef EQUAL_EPSILON
#define EQUAL_EPSILON   0.001
#endif

//#include "util_heap.h"
#include "q_platform.hpp"
struct cplane_s;

extern "C"
{
    extern vec4_t colorYellow;
    extern vec4_t colorWhiteFaded;
    extern vec4_t colorRedFaded;
    extern vec4_t colorOrange;
    extern vec4_t colorLtGrey;
    extern vec4_t colorWhite;
    extern vec4_t colorCyan;
    extern vec4_t colorBlue;
    extern vec4_t colorGreen;
    extern vec4_t colorLtGreen;
    extern vec4_t colorRed;

    void __cdecl YawVectors2D(const float yaw, vec2_t forward, vec2_t right);
    double __cdecl AngleDelta(const float angle1, const float angle2);
    double vectopitch(const float *vec);
    void AddLeanToPosition(float *position, const float fViewYaw, const float fLeanFrac, const float fViewRoll, const float fLeanDist);
    int BoxDistSqrdExceeds(const float *absmin, const float *absmax, const float *org, const float fogOpaqueDistSqrd);
    float vectoyaw( const vec3_t vec );
    vec_t Vec2Normalize( vec3_t v );
    double __cdecl PitchForYawOnNormal(const float fYaw, const vec3_t normal);
    double __cdecl AngleNormalize360(const float angle);
    void __cdecl Sys_SnapVector(vec3_t v);
    void __cdecl ProjectPointOnPlane(const float *p, const float *normal, float *dst);
    long double __cdecl randomf();
    double __cdecl DiffTrack(float tgt, float cur, float rate, float deltaTime);
    double __cdecl DiffTrackAngle(float tgt, float cur, float rate, float deltaTime);
    double __cdecl Vec2NormalizeTo(const float *v, float *out);
    void __cdecl ExpandBoundsToWidth(float *mins, float *maxs);
    void AxisToAngles( vec3_t axis[3], vec3_t angles );
    byte __cdecl DirToByte(const vec3_t dir);
    void __cdecl PerpendicularVector(const vec3_t src, vec3_t dst);
    long double crandom();
    void __cdecl ms_srand(int seed);
    void __cdecl Rand_Init(int seed);
    void __cdecl YawVectors(const float yaw, vec3_t forward, vec3_t right);
    float Q_acos( float c );
    double vectosignedyaw(float *vec);
    void __cdecl VectorAngleMultiply(float *vec, float angle);
    double __cdecl Vec2Distance(const float *v0, const float *v1);
    int __cdecl irand(int min, int max);
    double __cdecl flrand(float min, float max);
    void __cdecl ExtendBounds(vec3_t mins, vec3_t maxs, const vec3_t offset);
    double __cdecl LinearTrackAngle(float tgt, float cur, float rate, float deltaTime);
    void __cdecl MatrixInverseOrthogonal43(const float in[4][3], float out[4][3]);
    void AxisClear( vec3_t axis[3] );


#ifndef BSPC
int BoxOnPlaneSide( vec3_t emins, vec3_t emaxs, struct cplane_s *p );
#endif

// 0x081921A2
void Math_VectorToAngles(vec3_t vector, vec3_t angles);
void vectoangles( const vec3_t value1, vec3_t angles );
void AngleVectors( const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up );
float RadiusFromBounds( const vec3_t mins, const vec3_t maxs );

vec_t Vec3Normalize( vec3_t v );
vec_t VectorNormalize2( const vec3_t v, vec3_t out );
vec_t Vec3NormalizeTo( const vec3_t v, vec3_t out );

void VectorInverse( vec3_t v );
#define Vec3Length VectorLength
vec_t VectorLength( const vec3_t v );
vec_t VectorLengthSquared( const vec3_t v );

int VectorCompare( const vec3_t v1, const vec3_t v2 );
float VectorDistance( vec3_t v1, vec3_t v2 );
vec_t Distance( const vec3_t p1, const vec3_t p2 ) ;
void AnglesToAxis( const vec3_t angles, vec3_t axis[3] );
void  SnapAngles(float *vAngles);

double __cdecl Vec3DistanceSq(const float *p1, const float *p2);
float vec2_maxabs    (vec2_t v);


float Q_fabs(float f);
vec_t Q_rint( vec_t in );

void MatrixTransposeTransformVector43(const vec3_t in1, const float in2[4][3], vec3_t out);
void MatrixTransformVector(const vec3_t in1, const float in2[3][3], vec3_t out);
void Vec3Lerp(const float *start, const float *end, const float fraction, float *endpos);
double Vec2DistanceSq(const float *v0, const float *v1);
void MatrixTransformVector43(const vec3_t in1, const float in2[4][3], vec3_t out);
void __cdecl MatrixTranspose(const float (*in)[3], float (*out)[3]);
void MatrixMultiply( float in1[3][3], float in2[3][3], float out[3][3] );
void AddPointToBounds( const vec3_t v, vec3_t mins, vec3_t maxs );
void ClearBounds(vec3_t mins, vec3_t maxs);
void CreateRotationMatrix( const vec3_t angles, vec3_t matrix[3] );
void RotatePoint( vec3_t point, const vec3_t matrix[3] );

#include <xmmintrin.h>


    void __cdecl AnglesToQuat(const float *angles, float *quat);
    unsigned int __cdecl ms_rand();
    void __cdecl AnglesSubtract(const vec3_t v1, const vec3_t v2, vec3_t v3);
    double RotationToYaw(float *rot);
    void __cdecl YawToAxis(float yaw, vec3_t axis[3]);
    void __cdecl MatrixMultiply43(const float (*in1)[3], const float (*in2)[3], float (*out)[3]);
    double __cdecl ColorNormalize(const float *in, float *out);
    void __cdecl AxisToQuat(vec3_t mat[3], float *out);
    void __cdecl QuatSlerp(const float *from, const float *to, float frac, float *result);
    float Vec4Normalize( vec4_t v );
    void __cdecl UnitQuatToForward(const float *quat, float *forward);
    void __cdecl NearestPitchAndYawOnPlane(const float *angles, const float *normal, float *result);
    void __cdecl AxisTransformVec3(const vec3_t axes[3], const vec3_t vec, vec3_t out);
    void __cdecl QuatToAxis(const float *quat, vec3_t axis[3]);
    void AxisCopy( vec3_t in[3], vec3_t out[3] );
    void __cdecl QuatLerp(const float *qa, const float *qb, float frac, float *out);
    void __cdecl ShrinkBoundsToHeight(vec3_t mins, vec3_t maxs);
    void __cdecl MatrixIdentity33(float (*out)[3]);
    qboolean __cdecl IntersectPlanes(const float **plane, float *xyz);
    void __cdecl SnapPointToIntersectingPlanes(const float **planes, float *xyz, float snapGrid, float snapEpsilon);
    qboolean __cdecl PlaneFromPoints(float *plane, const float *v0, const float *v1, const float *v2);
    qboolean __cdecl VecNCompareCustomEpsilon(const float *v0, const float *v1, float epsilon, int coordCount);
    void __cdecl MatrixTransposeTransformVector(const float *in1, const vec3_t in2[3], float *out);
    void __cdecl ExpandBounds(const vec3_t addedmins, const vec3_t addedmaxs, vec3_t mins, vec3_t maxs);

    extern vec3_t vec3_origin;
} // extern "C"

float AngleNormalize180 ( float angle );
int f2rint(float f);

#define	ANGLE2SHORT(x)	((int)((x)*65536.0f/360.0f) & 65535)
#define	SHORT2ANGLE(x)	((x)*(360.0/65536))
