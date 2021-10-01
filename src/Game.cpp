/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/01 17:09:47 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "All.hpp"

Game::Game(void) : game_speed(1.0f), gravity(9.80665f) { }
Game::~Game(void) { }

void	Game::init(void)
{
	Object	tmp;
	Object	tmp2;

	/* initial camera position, unlocked */
	SDL_SetRelativeMouseMode(SDL_TRUE);
	this->pos[2] = -4.0f;
	this->pos[1] = 1.0f;
	this->pos_locked = 8.0f;
	this->obj.reserve(1000);


	/* obj[0] Tronc*/
	tmp.model = Matrix();
	tmp.rotate = Matrix().rotate(0,0,0);
	tmp.translate = Matrix().translate(0,0,0);
	tmp.root_part = 0;
	tmp.dimensions = {1.5,5,1.5};
	this->obj.push_back(tmp);

	/* obj[1] tete*/
	tmp.model = Matrix();
	tmp.rotate = Matrix().rotate(0,0,0);
	tmp.translate = Matrix().translate(0,3,0);
	tmp.root_part = &this->obj[0];
	tmp.dimensions = {2,2,2};
	this->obj.push_back(tmp);

	/* obj[2] articulation bras droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(1.2,1.5,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);

	/* obj[3] bras droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[2];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);

	/* obj[4] articulation bras gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(-1.2,1.5,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);


	/* obj[5] bras gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[4];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);


/* obj[6] articulation jambe droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0.3,-2.5,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);

	/* obj[7] articulation jambe gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(-0.3,-2.5,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);


	/* obj[8] jambe droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[6];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);


	/* obj[9] jambe gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[7];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);


	/* obj[10] articulation coude droit */
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[3];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);	
	
	/* obj[11] articulation coude gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[5];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);

	/* obj[12] avant bras droit */
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[10];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);	
	
	/* obj[13] avant bras gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[11];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);

	/* obj[14] articulation rotule droit */
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[8];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);	
	
	/* obj[15] articulation rotule gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[9];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);


	/* obj[16] molet droit */
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[14];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);	
	
	/* obj[17] molet gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[15];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);

}

/* ########################################################################## */

void		Game::_update_camera(float delta, const Keys &key)
{
	float	delta_x;
	float	delta_z;

	/* lock - unlock camera and cursor */
	if (this->camera_lock != (enum e_camera)key.mouse_middle)
	{
		this->camera_lock = key.mouse_middle ? Locked : Unlocked;
		if (this->camera_lock == Unlocked)
			SDL_SetRelativeMouseMode(SDL_TRUE);
		else if (this->camera_lock == Locked)
			SDL_SetRelativeMouseMode(SDL_FALSE);
	}

	/* set then cap look angles */
	this->look_yaw += (key.mouse_x * MOUSE_SENSITIVITY_X) / 100000.0f;
	this->look_pitch += (key.mouse_y * MOUSE_SENSITIVITY_Y) / 100000.0f;
	if (this->look_pitch < -LOOK_CAP_PITCH)
		this->look_pitch = -LOOK_CAP_PITCH;
	if (this->look_pitch > LOOK_CAP_PITCH)
		this->look_pitch = LOOK_CAP_PITCH;
	if (this->camera_lock == Locked && this->look_pitch < LOOK_CAP_PITCH_LOCK)
		this->look_pitch = LOOK_CAP_PITCH_LOCK;

	/* set and cap positions */
	this->pos[1] += (unsigned)key.space * delta * CAMERA_SPEED -
	(unsigned)key.lshift * delta * CAMERA_SPEED;
	if (this->pos[1] < POS_CAP_Y)
		this->pos[1] = POS_CAP_Y;
	
	delta_x = (unsigned)key.d * delta * CAMERA_SPEED -
	(unsigned)key.a * delta * CAMERA_SPEED;
	delta_z = (unsigned)key.w * delta * CAMERA_SPEED -
	(unsigned)key.s * delta * CAMERA_SPEED;
	this->pos[0] += delta_z * sinf(this->look_yaw) +
	delta_x * sinf(this->look_yaw + (float)M_PI_2);
	this->pos[2] += delta_z * cosf(this->look_yaw) +
	delta_x * cosf(this->look_yaw + (float)M_PI_2);

	this->pos_locked += key.mouse_scroll / 1000.0f * SCROLL_SENSITIVITY;
	if (this->pos_locked < 0)
		this->pos_locked = 0;

	glUniform3fv(all.gl.uniform.camera_pos, 1, this->pos.data());
}

void		Game::_update_objects(float delta, const Keys &key)
{
	(void)key;
	static float	elapsed_time = 0;
	static float 	anim = 0;

	delta *= this->game_speed;

	
	elapsed_time += delta;

	



	// for (Object &obj : this->obj)
	// {
	// 	obj.position[0] += obj.velocity[0] * delta;
	// 	obj.position[1] += obj.velocity[1] * delta;
	// 	obj.position[2] += obj.velocity[2] * delta;
	// 	obj.angular_position[0] += obj.angular_velocity[0] * delta;
	// 	obj.angular_position[1] += obj.angular_velocity[1] * delta;
	// 	obj.angular_position[2] += obj.angular_velocity[2] * delta;
	// }
	
	
	


 	std::cout << delta << std::endl;
 	std::cout << elapsed_time << std::endl;
 	std::cout << cos(elapsed_time)<< std::endl;
 	std::cout << cos(elapsed_time) * delta<< std::endl;
 	std::cout << anim << std::endl;
	
	// if (cos(elapsed_time))



obj[2].rotate.rotate(cos(elapsed_time) * delta, 0, 0);
 obj[4].rotate.rotate(cos(elapsed_time) * -delta , 0, 0);
 obj[6].rotate.rotate(cos(elapsed_time) * delta , 0, 0);
 obj[7].rotate.rotate(cos(elapsed_time) * -delta , 0, 0);

 	obj[10].rotate.rotate((sin(elapsed_time) * delta)/2 , 0, 0);
 	obj[11].rotate.rotate((sin(elapsed_time) * delta)/2 , 0, 0);




//  obj[14].rotate.rotate(cos(elapsed_time) * -delta , 0, 0);
//  obj[15].rotate.rotate(cos(elapsed_time) * delta , 0, 0);
	 
	 
	 
	 
	 
	 
	 
	 // 		//  std::cout << anim << std::endl;

	
 		// if (anim == 0)
		// {
 		// 	// std::cout << obj[1].angular_position[0] << std::endl;
			
		// 	obj[1].model.translate(0, 0, 0).rotate(delta, 0, 0);
		// 	 if (obj[1].angular_position[0] >= 0.5){
		// 		 anim = 1;

				
		// 	}
		// }

		// if (anim == 1)
		// {
		
		// }
	

	



// 	for (Object &obj : this->obj)
// 	{
// 		if (delta < 0.1)
// 		{

// 		}
// 		else{

// //			obj.position[4] -=  delta ;
// 		}

		
	// }
	/* wiggle all */
	// this->obj[2].position[0] = sinf(all.time.elapsed_frame() / 20.0f) * 4.8f;
	// this->obj[2].position[2] = cosf(all.time.elapsed_frame() / 20.0f) * 4.8f;
	// this->obj[1].position[0] = 1 + cosf(all.time.elapsed_frame() / 60.0f) * 1.8f;
	// this->obj[1].position[1] = sinf(all.time.elapsed_frame() / 60.0f) * 1.8f;
	// this->obj[2].dimension[0] = sinf(all.time.elapsed_frame() / 10.0f) * 1.8f;
	// this->obj[2].dimension[1] = cosf(all.time.elapsed_frame() / 8.0f) * 2.3f;
	// this->obj[2].dimension[2] = -cosf(all.time.elapsed_frame() / 3.0f) * 5.0f;
}

void		Game::update(float delta, const Keys &key)
{
	this->_update_camera(delta, key);
	this->_update_objects(delta, key);
}
