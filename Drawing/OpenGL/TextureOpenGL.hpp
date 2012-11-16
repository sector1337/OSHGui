/*
 * OldSchoolHack GUI
 *
 * Copyright (c) 2012 KN4CK3R http://www.oldschoolhack.de
 *
 * See license in OSHGui.hpp
 */

#ifndef OSHGUI_DRAWING_TEXTUREOPENGL_HPP
#define OSHGUI_DRAWING_TEXTUREOPENGL_HPP

#include <vector>

#include "../ITexture.hpp"

namespace OSHGui
{
	namespace Drawing
	{
		class OSHGUI_EXPORT TextureOpenGL : public ITexture
		{
		public:
			using ITexture::Fill;
			using ITexture::FillGradient;
			using ITexture::Insert;

			/**
			 * Konstruktor der Klasse.
			 *
			 * @param device Zeiger auf ein initialisiertes IDirect3DDevice9-Objekt.
			 * @param size die Gr��e
			 * @param frameCount die Anzahl der Frames (default: 1)
			 * @param frameChangeInterval das Interval, in dem sich ein Frame �ndert (default: 125ms)
			 */
			TextureOpenGL(const Size &size, int frameCount = 1, Misc::TimeSpan frameChangeInterval = Misc::TimeSpan::FromMilliseconds(125));
			/**
			 * Konstruktor der Klasse.
			 *
			 * @param device Zeiger auf ein initialisiertes IDirect3DDevice9-Objekt.
			 * @param width
			 * @param height
			 * @param frameCount die Anzahl der Frames (default: 1)
			 * @param frameChangeInterval das Interval, in dem sich ein Frame �ndert (default: 125ms)
			 */
			TextureOpenGL(int width, int height, int frameCount = 1, Misc::TimeSpan frameChangeInterval = Misc::TimeSpan::FromMilliseconds(125));
			/**
			 * Konstruktor der Klasse.
			 *
			 * @param device Zeiger auf ein initialisiertes IDirect3DDevice9-Objekt.
			 * @param filename Pfad zur zu ladenden Datei
			 */
			TextureOpenGL(const Misc::AnsiString &filename);
			virtual ~TextureOpenGL();
			
			/**
			 * Ruft ab, ob die Textur gesperrt ist.
			 */
			virtual bool IsLocked() const;

			/**
			 * L�dt eine Textur aus einer Datei.
			 *
			 * @param filename der Dateipfad
			 * @return gibt den Status der Operation zur�ck
			 */
			virtual void LoadFromFile(const Misc::AnsiString &filename);

			/**
			 * Sperrt die Textur, damit sie ver�ndert werden kann.
			 * Muss einmalig vor dem Aufrufen von Clear, Fill, FillGradient, Rotate oder Insert aufgerufen werden.
			 */
			virtual void BeginUpdate();
			/**
			 * Entsperrt die Textur.
			 * Muss einmalig nach dem Aufrufen von Clear, Fill, FillGradient, Rotate oder Insert aufgerufen werden.
			 */
			virtual void EndUpdate();
			
			/**
			 * F�llt das Rechteck.
			 *
			 * @param x
			 * @param y
			 * @param w
			 * @param h
			 * @param color die Farbe
			 */
			virtual void Fill(int x, int y, int w, int h, Color color);

			/**
			 * F�llt das Rechteck mit einem Farbverlauf.
			 *
			 * @param x
			 * @param y
			 * @param w
			 * @param h
			 * @param from die Startfarbe
			 * @param to die Endfarbe
			 * @param updown (optional: die Richtung des Farbverlaufs. Standard: von oben nach unten)
			 */
			virtual void FillGradient(int x, int y, int w, int h, Color from, Color to, bool updown = true);
			
			/**
			 * Dreht die Textur um die angegebene Gradzahl.
			 * Achtung: Bei einer Gradzahl != x*90� ver�ndert sich die Gr��e der Textur!
			 *
			 * @param degrees die Gradzahl 0-360
			 */
			virtual void Rotate(int degrees);

			/**
			 * F�gt eine Textur am angegebenen Punkt in diese Textur ein.
			 *
			 * @param x
			 * @param y
			 * @param texture die Textur
			 */
			virtual void Insert(int x, int y, const std::shared_ptr<ITexture> &texture);

			//Animation
			/**
			 * Ruft ab, wieviele Frames die Textur beinhaltet.
			 *
			 * @return Anzahl der Frames
			 */
			virtual int GetFrameCount() const;
			/**
			 * F�gt einen neuen Frame hinzu.
			 *
			 * @param frame der Frame
			 */
			virtual void AddFrame(const std::shared_ptr<ITexture> &frame);
			/**
			 * Legt den Frame fest, auf den �nderungsmethoden angewandt werden.
			 *
			 * @param frame der Frame Index zwischen 0 und GetFrameCount()
			 */
			virtual void SelectActiveFrame(int frame);
			
		protected:
			/**
			 * Erzeugt intern eine neue Textur mit der entsprechenden Gr��e und der Anzahl der Frames.
			 *
			 * @param size die Gr��e
			 * @param frameCount die Anzahl der Frames
			 * @return gibt den Status der Operation zur�ck
			 */
			virtual void Create(const Size &size, int frameCount = 1);

		private:
		};
	}
}

#endif