#version 120

attribute vec2 a_Position;
attribute vec4 a_Color;
uniform float u_XOffset;
uniform float u_YOffset;
uniform vec2 u_CamPos;
uniform vec2 u_CamSca;
varying vec4 v_Color;

void main()
{
	v_Color = a_Color;

	vec2 pos = a_Position/110.0;
	pos.x += u_XOffset;
	pos.y += u_YOffset;

	pos-= u_CamPos;

	pos *= vec2(1/u_CamSca.x, 1/u_CamSca.y);

    gl_Position = vec4( pos, 0, 1 );
}