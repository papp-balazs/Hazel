#pragma once

#include "Core.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Hazel
{

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		
		void OnEvent(Event& e);

		void Run();
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running = true;
	};

	// To be defined in the CLIENT.
	Application* CreateApplication();

}