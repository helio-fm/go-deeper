/*
  ==============================================================================

    XMLSerializer.cpp
    Created: 18 Nov 2015 10:44:06am
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "XMLSerializer.h"

XMLSerializer::Context::Context(XmlElement *rootElement) : root(rootElement)
{
    jassert(this->root != nullptr);
}

void XMLSerializer::Context::setRealProperty(double value, const std::string &key)
{
    jassert(this->root != nullptr);
    this->root->setAttribute(String(key), value);
}

double XMLSerializer::Context::getRealProperty(const std::string &key) const
{
    jassert(this->root != nullptr);
    return this->root->getDoubleAttribute(String(key), 0.0);
}

void XMLSerializer::Context::setNumberProperty(long long value, const std::string &key)
{
    jassert(this->root != nullptr);
    this->root->setAttribute(String(key), double(value));
}

long long XMLSerializer::Context::getNumberProperty(const std::string &key) const
{
    jassert(this->root != nullptr);
    return this->root->getDoubleAttribute(String(key), 0.0);
}

void XMLSerializer::Context::setStringProperty(const std::string &value, const std::string &key)
{
    jassert(this->root != nullptr);
    this->root->setAttribute(String(key), String(value));
}

std::string XMLSerializer::Context::getStringProperty(const std::string &key) const
{
    jassert(this->root != nullptr);
    return this->root->getStringAttribute(String(key), "").toStdString();
}

size_t XMLSerializer::Context::getNumChildrenContexts() const
{
    jassert(this->root != nullptr);
    return this->root->getNumChildElements();
}

TinyRNN::SerializationContext::Ptr XMLSerializer::Context::getChildContext(int index) const
{
    jassert(this->root != nullptr);
    SerializationContext::Ptr child(new XMLSerializer::Context(this->root->getChildElement(index)));
    return child;
}

TinyRNN::SerializationContext::Ptr XMLSerializer::Context::getChildContext(const std::string &key) const
{
    jassert(this->root != nullptr);
    SerializationContext::Ptr child(new XMLSerializer::Context(this->root->getChildByName(String(key))));
    return child;
}

TinyRNN::SerializationContext::Ptr XMLSerializer::Context::createChildContext(const std::string &key)
{
    jassert(this->root != nullptr);
    // todo prepend child?
    XmlElement *newChild = this->root->createNewChildElement(String(key));
    SerializationContext::Ptr newChildContext(new XMLSerializer::Context(newChild));
    return newChildContext;
}


String XMLSerializer::serialize(TinyRNN::SerializedObject::Ptr target, const std::string &rootNodeName) const
{
    ScopedPointer<XmlElement> xml(new XmlElement(rootNodeName));
    XMLSerializer::Context::Ptr context(new XMLSerializer::Context(xml));
    target->serialize(context);
    return xml->createDocument("");
}

void XMLSerializer::deserialize(TinyRNN::SerializedObject::Ptr target, const std::string &data)
{
    if (ScopedPointer<XmlElement> xml = XmlDocument::parse(data))
    {
        XMLSerializer::Context::Ptr context(new XMLSerializer::Context(xml));
        target->deserialize(context);
    }
}
