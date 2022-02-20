cbuffer ConstantBuffer:register(b0)
{
	matrix CB_MatrixWorld;
	matrix CB_MatrixView;
	matrix CB_MatrixProjection;
}

cbuffer LightDiffuse:register(b11)
{
	float4 CB_LightDiffuseColor;
	float4 CB_LightDiffusePos;
	float4 CB_LightDiffuseDir;
}

struct VS_INPUT
{
	float4 Pos : POSITION;
	float4 Nor : NORMAL0;
	float4 Col : COLOR0;
	float2 Tex : TEXCOORD0;
};

struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float4 Col : COLOR0;
	float2 Tex : TEXCOORD0;
	//float4 Temp : TEXCOORD1;
};

// f(l,v) = Lo(v) / (El * CosQi)
// Lo(v) = f(l,v) * El * CosQi;


// 单纯漫反射
float3 BRDF_DIFF(float3 vNor, float3 lDir, float3 lDiff)
{
	return lDiff * max(0, dot(vNor, lDir));
	//return max(0, dot(vNor, lDir));
}
// 漫反射+镜面高光
float3 BRDF_DIFF_SPEC(
	float3 lDir, float3 lCol, 
	float3 ePos,
	float3 vPos,
	float3 vNor,float3 vDiffCol, float vRoughness,
	float3 vSpecCol,float vSpecM)
{
	float cosLV = max(0, dot(vNor, lDir));
	float3 eyeDir = normalize(vPos - ePos);
	float3 eyeReflect = reflect(eyeDir, vNor);
	return vDiffCol * cosLV * vRoughness + 
			(vSpecM + 2) * vSpecCol * pow(cos(eyeReflect), vSpecM) * 0.5 * (1 - vRoughness);
}

PS_INPUT VS(VS_INPUT vIn)
{
	PS_INPUT output = (PS_INPUT)0;

	float4 wPos = mul(vIn.Pos, CB_MatrixWorld);
	float4 wNor = mul(vIn.Nor, CB_MatrixWorld);

	output.Pos = wPos;
	output.Pos = mul(output.Pos, CB_MatrixView);
	output.Pos = mul(output.Pos, CB_MatrixProjection);

	output.Col = float4(vIn.Col * BRDF_DIFF(wNor, CB_LightDiffuseDir, CB_LightDiffuseColor), vIn.Col.a);
	//output.Col = CB_LightDiffuseColor;
	//output.Col = vIn.Col;

	output.Tex = vIn.Tex;


	return output;
}

float4 PS(PS_INPUT vIn) : SV_Target
{
	return vIn.Col;
//return CB_LightDiffusePos;
//return float4(1,1,1,1);
}
