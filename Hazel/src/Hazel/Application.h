#pragma once

#include "Core.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

#include "Hazel/ImGui/ImGuiLayer.h"

#include "Hazel/Renderer/Shader.h"

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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;
		bool m_Running = true;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	// To be defined in the CLIENT.
	Application* CreateApplication();

}
