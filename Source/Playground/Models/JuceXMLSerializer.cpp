/*
  ==============================================================================

    XMLSerializer.cpp
    Created: 18 Nov 2015 10:44:06am
    Author:  Peter Rudenko

  ==============================================================================
*/

#include "Precompiled.h"
#include "JuceXMLSerializer.h"

JuceXMLSerializer::Context::Context(XmlElement *rootElement) : root(rootElement)
{
    jassert(this->root != nullptr);
}

void JuceXMLSerializer::Context::setRealProperty(TinyRNN::Value value, const std::string &key)
{
    jassert(this->root != nullptr);
    this->root->setAttribute(String(key), value);
}

TinyRNN::Value JuceXMLSerializer::Context::getRealProperty(const std::string &key) const
{
    jassert(this->root != nullptr);
    return this->root->getDoubleAttribute(String(key), 0.0);
}

void JuceXMLSerializer::Context::setNumberProperty(long long value, const std::string &key)
{
    jassert(this->root != nullptr);
    this->root->setAttribute(String(key), double(value));
}

long long JuceXMLSerializer::Context::getNumberProperty(const std::string &key) const
{
    jassert(this->root != nullptr);
    return this->root->getDoubleAttribute(String(key), 0.0);
}

void JuceXMLSerializer::Context::setStringProperty(const std::string &value, const std::string &key)
{
    jassert(this->root != nullptr);
    this->root->setAttribute(String(key), String(value));
}

std::string JuceXMLSerializer::Context::getStringProperty(const std::string &key) const
{
    jassert(this->root != nullptr);
    return this->root->getStringAttribute(String(key), "").toStdString();
}

size_t JuceXMLSerializer::Context::getNumChildrenContexts() const
{
    jassert(this->root != nullptr);
    return this->root->getNumChildElements();
}

TinyRNN::SerializationContext::Ptr JuceXMLSerializer::Context::getChildContext(int index) const
{
    jassert(this->root != nullptr);
    SerializationContext::Ptr child(new JuceXMLSerializer::Context(this->root->getChildElement(index)));
    return child;
}

TinyRNN::SerializationContext::Ptr JuceXMLSerializer::Context::getChildContext(const std::string &key) const
{
    jassert(this->root != nullptr);
    SerializationContext::Ptr child(new JuceXMLSerializer::Context(this->root->getChildByName(String(key))));
    return child;
}

TinyRNN::SerializationContext::Ptr JuceXMLSerializer::Context::addChildContext(const std::string &key)
{
    jassert(this->root != nullptr);
    XmlElement *newChild = this->root->createNewChildElement(String(key));
    SerializationContext::Ptr newChildContext(new JuceXMLSerializer::Context(newChild));
    return newChildContext;
}

TinyRNN::SerializationContext::Ptr JuceXMLSerializer::Context::addChildContextUnordered(const std::string &key)
{
    jassert(this->root != nullptr);
    XmlElement *newChild = new XmlElement(String(key));
    this->root->prependChildElement(newChild);
    SerializationContext::Ptr newChildContext(new JuceXMLSerializer::Context(newChild));
    return newChildContext;
}

String JuceXMLSerializer::serialize(TinyRNN::SerializedObject::Ptr target, const std::string &rootNodeName) const
{
    ScopedPointer<XmlElement> xml(new XmlElement(rootNodeName));
    JuceXMLSerializer::Context::Ptr context(new JuceXMLSerializer::Context(xml));
    target->serialize(context);
    return xml->createDocument("");
}

void JuceXMLSerializer::deserialize(TinyRNN::SerializedObject::Ptr target, const std::string &data)
{
    if (ScopedPointer<XmlElement> xml = XmlDocument::parse(data))
    {
        std::cout << "xml tag: " <<  xml->getTagName().toStdString() << std::endl;
        JuceXMLSerializer::Context::Ptr context(new JuceXMLSerializer::Context(xml));
        target->deserialize(context);
    }
}
