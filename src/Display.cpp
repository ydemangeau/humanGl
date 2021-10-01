/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:03:42 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/01 13:12:23 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <OpenGL/gl3.h>

#include "Display.hpp"
#include "General.hpp"	/* OPENGL defines */


Display::Display(void) { }
Display::Display(const Display &) { }
Display::~Display(void) { }

void	Display::init(void)
{
	this->res_x = 1920;
	this->res_y = 1080;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(0);

	/* This is out of place, i have no way around */
	if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE) < 0 ||
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,
			OPENGL_VERSION_MAJOR) < 0 ||
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,
			OPENGL_VERSION_MINOR) < 0 ||
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8) < 0)
		exit(0);

	/* create window */
	if (!(this->window = SDL_CreateWindow(WIN_TITLE, WIN_POSX, WIN_POSY,
				WIN_SIZEX, WIN_SIZEY, SDL_WINDOW_OPENGL)))
		exit(0);
}

// Le VBO contiens 1, 2, 3, 4, 5, 6 etc etc, et les matrices sont toutes passées
// dans un tableau d'uniforme au vertex shader, qui selectionne la bonne et la file
// au geometry shader, qui dessine la figure a partir de la matrice.
// La matrice est passée en tant que matrice 3x4, puis reconstituée comme 4x4 par
// le vertex shader.

/* ########################################################################## */

#include "Utils.hpp"
#include "All.hpp"

static void	_draw_floor(void)
{
	Matrix model;

	model.scale(10000, 0, 10000).translate(0, -0.5f, 0);
	glUniformMatrix4fv(all.gl.uniform.matrix_model, 1, true, model.data());
	glUniform1i(all.gl.uniform.color, 0xf5f5f5);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);	/* top */
}

void		Display::update(const Game &game)
{
	Matrix	view;
	vec3	inv_pos;
	vec3	dir;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// _draw_floor();

	/* camera matrix and look is inverted */
	inv_pos = {-game.pos[0], -game.pos[1], -game.pos[2]};
	if (game.camera_lock == Unlocked)
		view = view.translate(inv_pos).rotate(-game.look_pitch, -game.look_yaw,
			0);
	else if (game.camera_lock == Locked)
		view = view.rotate(-game.look_pitch, -game.look_yaw, 0).translate(0, 0,
			game.pos_locked);
	glUniformMatrix4fv(all.gl.uniform.matrix_view, 1, true, view.data());
	
	static float roty = 0;
	roty += 0.04f;
	std::cout << "obj[0]:" << std::endl << all.game.obj[0].model << std::endl;
	std::cout << "obj[1]:" << std::endl << all.game.obj[1].model << std::endl;
	std::cout << "obj[2]:" << std::endl << all.game.obj[2].model << std::endl;
	std::cout << std::endl << std::endl;

	//  std::cout << "obj[0].root_part:"<< all.game.obj[0].root_part << std::endl;
	//  std::cout << "obj[1].root_part:"<< all.game.obj[1].root_part->root_part << std::endl;
	// std::cout << "obj[2].root_part:"<< all.game.obj[2].root_part->root_part->root_part << std::endl;

	for (Object &obj : all.game.obj)
	{

		 Utils::draw_cube((obj.GetModel()) * Matrix().scale(obj.dimensions));
	}
	// std::cout << std::endl << std::endl;
	// std::cout << std::endl << std::endl;

	glFinish();
	SDL_GL_SwapWindow(this->window);
}
