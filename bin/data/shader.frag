#version 150

uniform sampler2DRect tex;
uniform float dR;

in vec2 texCoordVarying;

out vec4 outputColor;

void main(){
	vec2 pos = texCoordVarying.xy;
	vec4 col;

	float decayRate = dR;

	//DIFFUSE
	col = texture(tex, pos);
	col += texture(tex, pos + vec2(-1,-1));
	col += texture(tex, pos + vec2(0,-1));
	col += texture(tex, pos + vec2(1,-1));
	col += texture(tex, pos + vec2(-1,0));
	col += texture(tex, pos + vec2(1,0));
	col += texture(tex, pos + vec2(-1,1));
	col += texture(tex, pos + vec2(0,1));
	col += texture(tex, pos + vec2(1,1));

	col /= 9.0;
	
	//DECAY
	col.rgb *= decayRate;

	outputColor = col;
}
