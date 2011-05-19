#version 120
varying vec4 vertColor;

void main()
{
	gl_FragColor = vertColor;
	//gl_FragColor = texture2D(texture, vertTexcoord);
	//vec2 texCoord = gl_TexCoord[0].xy;
	//vec2 paramU   = gl_TexCoord[1].xy;
	//vec2 paramV   = gl_TexCoord[2].xy;

	//texCoord.x = fract(texCoord.x) * paramU.x + paramU.y;
	//texCoord.y = fract(texCoord.y) * paramV.x + paramV.y;
//
	//gl_FragColor = gl_Color * texture2D(texture, texCoord);
	//	gl_FragColor = vec4(1.f,1.f,1.f,1.f);
}
