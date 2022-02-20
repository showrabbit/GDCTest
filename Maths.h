#pragma once

#include <math.h>

struct Matrix
{
	float M11, M12, M13, M14;
	float M21, M22, M23, M24;
	float M31, M32, M33, M34;
	float M41, M42, M43, M44;


	static Matrix Identity;
	static Matrix Transpose(Matrix* matrix)
	{
		Matrix ret = {};
		ret.M11 = matrix->M11;
		ret.M12 = matrix->M21;
		ret.M13 = matrix->M31;
		ret.M14 = matrix->M41;
		ret.M21 = matrix->M12;
		ret.M22 = matrix->M22;
		ret.M23 = matrix->M32;
		ret.M24 = matrix->M42;
		ret.M31 = matrix->M13;
		ret.M32 = matrix->M23;
		ret.M33 = matrix->M33;
		ret.M34 = matrix->M43;
		ret.M41 = matrix->M14;
		ret.M42 = matrix->M24;
		ret.M43 = matrix->M34;
		ret.M44 = matrix->M44;
		return ret;
	}
};


struct Vector2
{
	float X;
	float Y;
};

struct Vector3
{
	float X;
	float Y;
	float Z;

	static void Cross(Vector3* a, Vector3* b, Vector3* ret)
	{
		ret->X = a->Y * b->Z - b->Y * a->Z;
		ret->Y = a->Z * b->X - b->Z * a->X;
		ret->Z = a->X * b->Y - b->X * a->Y;
	}

	static float Dot(Vector3* a, Vector3* b)
	{
		return a->X * b->X + a->Y * b->Y + a->Z * b->Z;
	}

	static void Normalize(Vector3* a)
	{
		float len = sqrt(a->X * a->X + a->Y * a->Y + a->Z * a->Z);
		a->X = a->X / len;
		a->Y = a->Y / len;
		a->Z = a->Z / len;
	}
};

struct Vector4
{
	float X;
	float Y;
	float Z;
	float W;

	static void Dot(Vector4* vec, Matrix* mat, Vector4* ret)
	{
		ret->X = vec->X * mat->M11 + vec->Y * mat->M21 + vec->Z * mat->M31 + vec->W * mat->M41;
		ret->Y = vec->X * mat->M12 + vec->Y * mat->M22 + vec->Z * mat->M32 + vec->W * mat->M42;
		ret->Z = vec->X * mat->M13 + vec->Y * mat->M23 + vec->Z * mat->M33 + vec->W * mat->M43;
		ret->W = vec->X * mat->M14 + vec->Y * mat->M24 + vec->Z * mat->M34 + vec->W * mat->M44;
	}
};

struct Color
{
	float R, G, B, A;
};

struct VertexData
{
	Vector3 Pos;
};

struct VertexDataNormal
{
	Vector3 Pos;
	Color Col;
	Vector2 Tex;
	Vector3 Normal;
};