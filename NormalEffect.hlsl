cbuffer ConstantBuffer:register(b0)
{
	matrix World;
	matrix View;
	matrix Projection;
}

cbuffer LightDiffuse:register(b1)
{
	float4 Color;
	float4 Pos;
	float4 Dir;
}

struct VS_INPUT
{
	float4 Pos : POSITION;
	float4 Col : COLOR0;
	float2 Tex : TEXCOORD0;
	int Index : TEXCOORD1;
};

struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float4 Col : COLOR0;
	float2 Tex : TEXCOORD0;
	//float4 Temp : TEXCOORD1;
};

PS_INPUT VS(VS_INPUT vIn)
{
	PS_INPUT output = (PS_INPUT)0;

	// 向量在前 左乘 则矩阵为 行主矩阵
	// 矩阵在前 右乘 则矩阵为 列主矩阵
	output.Pos = mul(vIn.Pos, World);
	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);

	// 
	/*if (vIn.Index > -0.1 && vIn.Index < 0.1)
	{
		output.Pos = float4(-1.81066179, -5.28491592, 10.9504461, 11.8409424);
	}
	else if (vIn.Index > 0.9 && vIn.Index < 1.1)
		output.Pos = float4(1.81066179, -5.28491592, 10.9504461, 11.8409424);
	else if (vIn.Index > 1.9 && vIn.Index < 2.1)
		output.Pos = float4(1.81066179, -4.80446911, 8.94027042, 9.85086823);
	else
	{
		output.Pos = mul(vIn.Pos, World);
		output.Pos = mul(output.Pos, View);
		output.Pos = mul(output.Pos, Projection);
	}*/

	output.Col = vIn.Col;
	output.Tex = vIn.Tex;

	//output.Temp = output.Pos;

	return output;
}

float4 PS(PS_INPUT vIn) : SV_Target
{
	return vIn.Col;
}
