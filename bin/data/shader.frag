#version 120

uniform sampler2DRect tex;

void main(){
	vec2 pos = gl_TexCoord[0].xy;
	vec4 col;

	float decayRate = 0.85;

	//DIFFUSE
	col = texture2DRect(tex, pos);
	col += texture2DRect(tex, pos + vec2(-1,-1));
	col += texture2DRect(tex, pos + vec2(0,-1));
	col += texture2DRect(tex, pos + vec2(1,-1));
	col += texture2DRect(tex, pos + vec2(-1,0));
	col += texture2DRect(tex, pos + vec2(1,0));
	col += texture2DRect(tex, pos + vec2(-1,1));
	col += texture2DRect(tex, pos + vec2(0,1));
	col += texture2DRect(tex, pos + vec2(1,1));
	col /= 9.;

	//DECAY
	col.rgb *= decayRate;
	//col *= decayRate;

	gl_FragColor = col;
}