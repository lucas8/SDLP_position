
/*
 * Copyright (C) 2012 Chabassier Luc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*!
 * \file point_dec.hpp
 * \brief Définit la classe Point.
 */

#ifndef DEF_SDLP_POINT
#define DEF_SDLP_POINT

#include <SDL/SDL.h>
#include "vector2f.hpp"

namespace sdl
{
	template<typename Type>
		class Point
		{
			public:
				Type x; /*!< La position x du point. */
				Type y; /*!< La position y du point. */

				Point();
				Point(Type mx, Type my);
				explicit Point(Type all);
				Point(const SDL_Rect& cp);
				Point(const Point<Type>& cp);
				template<typename Cpt>
					Point(const Point<Cpt>& cp);
				~Point();

				Point& set(Type mx, Type my);
				Point& set(Type all);
				Point& set(const Point<Type>& cp);
				Point& set(const SDL_Rect& cp);
				template<typename Cpt>
					Point& set(const Point<Cpt>& cp);
				Point& clear();

				Point& operator=(const Point& cp);
				template<typename Cpt>
					Point& operator=(const Point<Cpt>& cp);
				operator SDL_Rect() const;
				operator SDL_Rect*() const;

				Point& translate(const Vector2f& v);

				Point operator+(const Vector2f& v) const;
				Point& operator+=(const Vector2f& v);

				Point operator-(const Vector2f& v) const;
				Point& operator-=(const Vector2f& v);

			private:
				mutable SDL_Rect* m_pointer; /*!< Pointeur temporaire servant à la convertion vers SDL_Rect*. */
		};

	typedef Point<signed int> Pointsi;
	typedef Point<unsigned int> Pointui;
	typedef Point<signed long> Pointsl;
	typedef Point<unsigned long> Pointul;
	typedef Point<float> Pointf;
};

#include "point_def.hpp"

#endif//DEF_SDLP_POINT
