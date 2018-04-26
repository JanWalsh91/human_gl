#ifndef SHADER_H
# define SHADER_H

# include <glad/glad.h>

# include <string>
# include <fstream>
# include <sstream>
# include <iostream>

class Shader {

	public:
		Shader( const char* vertexPath, const char* fragmentPath );
		Shader( Shader const & ) {};
		~Shader( void );
		Shader & operator=( Shader const & rhs );
		
		unsigned int	ID;

	private:
		Shader( void );
		void checkCompileErrors( unsigned int shader, std::string type );
		use( void );
		setBool( const std::string &name, bool value ) const;
		setInt( const std::string &name, int value ) const;
		setFloat( const std::string &name, float value) const;
		

};

#endif