#version 120

attribute vec2 a_Position;
attribute vec4 a_Color;
uniform float u_XOffset;
uniform float u_YOffset;
varying vec4 v_Color;

void main()
{
	v_Color = a_Color;

	vec2 pos = a_Position / 100.0;
	pos.x += u_XOffset;
	pos.y += u_YOffset;
    gl_Position = vec4( pos, 0, 1 );
}