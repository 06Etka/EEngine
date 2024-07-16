#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

uniform vec3 viewPos;
vec3 lightPosition = vec3(0.0, 3.0, 0.0);

void main() {
	vec3 ambient = 0.2 * texture(texture_diffuse1, TexCoords).rgb;

	vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = vec3(0.5) * diff * texture(texture_diffuse1, TexCoords).rgb;

	vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 8);
	vec3 specular = vec3(1.0) * spec * texture(texture_specular1, TexCoords).rgb;
	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0);
}
