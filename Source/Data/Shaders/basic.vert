#version 100

attribute vec2 a_Position;
uniform float u_XOffset;
uniform float u_YOffset;

void main()
{
	vec2 pos = a_Position / 50.0;
	pos.x += u_XOffset;
	pos.y += u_YOffset;
    gl_Position = vec4( pos, 0, 1 );
}