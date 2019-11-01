#define PI 3.1415926

uniform vec2 u_resolution;
uniform float u_time;
uniform float u_speedParticles;
uniform float u_speedColor;

void main()
{
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec3 color = vec3(0.0);
    vec2 pos = vec2(0.5)-st;
    float r = length(pos)*2.0;
    float a = atan(pos.x, pos.y);
    float f = cos(a*3.0);
    color = vec3(1.0-smoothstep(u_speedParticles*sin(f*u_time), f+0.02, r), sin(u_speedColor*u_time), 0.3);
    gl_FragColor = vec4(color, 1.0);
}
