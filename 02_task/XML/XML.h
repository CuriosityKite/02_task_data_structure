#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <windows.h>
#include <boost/foreach.hpp>

class Device
{
private:
	boost::property_tree::ptree ptree_;


	boost::property_tree::ptree& findNodeById(const std::string path, const std::string title, const std::string id)
	{
		BOOST_FOREACH(auto & node, ptree_.get_child(path))
		{
			if (node.first == title)
			{
				if (node.second.get("<xmlattr>.id", "") == id)
				{
					std::cout << "aswdwd";
					return node.second;
				}
				std::cout << "nen" << std::endl;
			}
		}
		throw std::runtime_error("Node not found");
	}

public:
	Device(const std::string brand, const std::string name, const std::string firmware)
	{
		ptree_.put("device.model.brand", brand);
		ptree_.put("device.model.name", name);
		ptree_.put("device.model.firmware", firmware);
	}

	void addCredentialsRef(const std::string& id)
	{
		boost::property_tree::ptree& node = ptree_.add("device.credentialsRef", "");
		node.put("<xmlattr>.id", id);
	}

	void addVideoSourceRef(const std::string& id)
	{
		boost::property_tree::ptree& node = ptree_.add("device.videoSourceRef", "");
		node.put("<xmlattr>.id", id);
	}

	void addVideoStreamingRef(const std::string parent_id, const std::string id, const bool is_default)
	{
		boost::property_tree::ptree& parent_node = findNodeById("device", "videoSourceRef", parent_id);
		boost::property_tree::ptree& node = parent_node.add("videoStreamingRef", "");

		node.put("<xmlattr>.id", id);
		node.put("<xmlattr>.default", is_default);
	}

	void addDetectorRef(const std::string parent_id, const std::string id, const std::string maxCount)
	{
		boost::property_tree::ptree& parent_node = findNodeById("device", "videoSourceRef", parent_id);
		boost::property_tree::ptree& node = parent_node.add("detectorRef", "");

		node.put("<xmlattr>.id", id);
		node.put("<xmlattr>.maxCount", maxCount);
	}

	void addTelemetryRef(const std::string& id)
	{
		boost::property_tree::ptree& node = ptree_.add("device.telemetryRef", "");
		node.put("<xmlattr>.id", id);
	}

	void addAudioSourceRef(const std::string& id)
	{
		boost::property_tree::ptree& node = ptree_.add("device.audioSourceRef", "");
		node.put("<xmlattr>.id", id);
	}

	void addAudioDestinationRef(const std::string& id)
	{
		boost::property_tree::ptree& node = ptree_.add("device.audioDestinationRef ", "");
		node.put("<xmlattr>.id", id);
	}

	void addSerialPortRef(const std::string& id)
	{
		boost::property_tree::ptree& node = ptree_.add("device.serialPortRef", "");
		node.put("<xmlattr>.id", id);
	}

	void addIoDeviceRef(const std::string& id)
	{
		boost::property_tree::ptree& node = ptree_.add("device.ioDeviceRef", "");
		node.put("<xmlattr>.id", id);
	}

	void display()
	{
		boost::property_tree::xml_writer_settings<std::string> settings(' ', 4);
		boost::property_tree::write_xml(std::cout, ptree_, settings);
	}
};