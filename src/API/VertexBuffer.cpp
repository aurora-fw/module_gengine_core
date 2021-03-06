/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#include <AuroraFW/GEngine/API/VertexBuffer.h>
#include <AuroraFW/GEngine/API/Context.h>
#include <AuroraFW/GEngine/GL/Buffer.h>

namespace AuroraFW::GEngine::API {
	VertexBuffer* VertexBuffer::Load(const void* data, size_t size, Buffer::Usage usage)
	{
		switch(Context::getRenderAPI())
		{
			case OpenGL: return reinterpret_cast<VertexBuffer*>(AFW_NEW GLBuffer(Buffer::Type::VertexBuffer, data, size, usage));
			case Vulkan:
				#pragma message("TODO: Need to be implemented")
				return AFW_NULLPTR;
			default: return AFW_NULLPTR;
		}
		return AFW_NULLPTR;
	}
}