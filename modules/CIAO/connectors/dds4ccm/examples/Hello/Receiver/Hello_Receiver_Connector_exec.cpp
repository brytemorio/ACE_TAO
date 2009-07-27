// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.9 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:1278

#define MAX_STRING_SIZE         1024

#include "Hello_Receiver_Connector_exec.h"
#include "ciao/CIAO_common.h"

#include "dds4ccm/impl/ndds/ParticipantFactory.h"

/* This method gets called back by DDS when one or more data samples have been
 * received.
 */
void HelloListener::on_data_available(DDSDataReader *reader) {
    /* Perform a safe type-cast from a generic data reader into a
     * specific data reader for the type "DDS::String"
     */
    DDSStringDataReader * string_reader = DDSStringDataReader::narrow(reader);
    if (!string_reader) {
        /* In this specific case, this will never fail */
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("DDSStringDataReader::narrow failed.\n")));
        return;
    }

    /* Loop until there are messages available in the queue */
    char                  sample[MAX_STRING_SIZE];
    char *ptr_sample = &sample[0];
    for(;;) {
        DDS_SampleInfo        info;
        DDS_ReturnCode_t retcode = string_reader->take_next_sample(
                            ptr_sample,
                            info);
        if (retcode == DDS_RETCODE_NO_DATA) {
            /* No more samples */
            break;
        } else if (retcode != DDS_RETCODE_OK) {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unable to take data from data reader, error %d.\n"), retcode));
            return;
        }
        if (info.valid_data) {
            // Valid (this isn't just a lifecycle sample): print it
            ACE_DEBUG ((LM_DEBUG, ACE_TEXT("%C\n"), sample));
            printf ("received string %s\n", sample);
        }
    }
}

namespace CIAO_Hello_DDS_Hello_receiver_Connector_Impl
{
  //============================================================
  // Facet Executor Implementation Class: string_Reader_exec_i
  //============================================================

  string_Reader_exec_i::string_Reader_exec_i (void)
  {
  }

  string_Reader_exec_i::~string_Reader_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::string_Reader

  void
  string_Reader_exec_i::read_all (
    ::CCM_DDS::string_Reader::stringSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    /* Your code here. */
  }

  void
  string_Reader_exec_i::read_all_history (
    ::CCM_DDS::string_Reader::stringSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    /* Your code here. */
  }

  void
  string_Reader_exec_i::read_one (
    char *& /* an_instance */,
    ::CCM_DDS::ReadInfo_out /* info */)
  {
    /* Your code here. */
  }

  void
  string_Reader_exec_i::read_one_history (
    const char * /* an_instance */,
    ::CCM_DDS::string_Reader::stringSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    /* Your code here. */
  }

  ::CCM_DDS::QueryFilter *
  string_Reader_exec_i::filter (void)
  {
    /* Your code here. */
    return 0;
  }

  void
  string_Reader_exec_i::filter (
    const ::CCM_DDS::QueryFilter & /* filter */)
  {
    /* Your code here. */
  }
  //============================================================
  // Facet Executor Implementation Class: ListenerControl_exec_i
  //============================================================

  ListenerControl_exec_i::ListenerControl_exec_i (void)
  {
  }

  ListenerControl_exec_i::~ListenerControl_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::ListenerControl

  ::CORBA::Boolean
  ListenerControl_exec_i::enabled (void)
  {
    /* Your code here. */
    return false;
  }

  void
  ListenerControl_exec_i::enabled (
    ::CORBA::Boolean /* enabled */)
  {
    /* Your code here. */
  }
  //============================================================
  // Facet Executor Implementation Class: DataReader_exec_i
  //============================================================

  DataReader_exec_i::DataReader_exec_i (void)
  {
  }

  DataReader_exec_i::~DataReader_exec_i (void)
  {
  }

  // Operations from ::DDS::DataReader

  ::DDS::ReturnCode_t
  DataReader_exec_i::enable (void)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::StatusCondition_ptr
  DataReader_exec_i::get_statuscondition (void)
  {
    /* Your code here. */
    return ::DDS::StatusCondition::_nil ();
  }

  ::DDS::StatusMask
  DataReader_exec_i::get_status_changes (void)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::InstanceHandle_t
  DataReader_exec_i::get_instance_handle (void)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReadCondition_ptr
  DataReader_exec_i::create_readcondition (
    ::DDS::SampleStateMask /* sample_states */,
    ::DDS::ViewStateMask /* view_states */,
    ::DDS::InstanceStateMask /* instance_states */)
  {
    /* Your code here. */
    return ::DDS::ReadCondition::_nil ();
  }

  ::DDS::QueryCondition_ptr
  DataReader_exec_i::create_querycondition (
    ::DDS::SampleStateMask /* sample_states */,
    ::DDS::ViewStateMask /* view_states */,
    ::DDS::InstanceStateMask /* instance_states */,
    const char * /* query_expression */,
    const ::DDS::StringSeq & /* query_parameters */)
  {
    /* Your code here. */
    return ::DDS::QueryCondition::_nil ();
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::delete_readcondition (
    ::DDS::ReadCondition_ptr /* a_condition */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::delete_contained_entities (void)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::set_qos (
    const ::DDS::DataReaderQos & /* qos */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_qos (
    ::DDS::DataReaderQos & /* qos */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::set_listener (
    ::DDS::DataReaderListener_ptr /* a_listener */,
    ::DDS::StatusMask /* mask */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::DataReaderListener_ptr
  DataReader_exec_i::get_listener (void)
  {
  return ::DDS::DataReaderListener::_nil ();
   // return new string_RawListener_exec_i (*this);
  }

  ::DDS::TopicDescription_ptr
  DataReader_exec_i::get_topicdescription (void)
  {
    /* Your code here. */
    return ::DDS::TopicDescription::_nil ();
  }

  ::DDS::Subscriber_ptr
  DataReader_exec_i::get_subscriber (void)
  {
    /* Your code here. */
    return ::DDS::Subscriber::_nil ();
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_sample_rejected_status (
    ::DDS::SampleRejectedStatus & /* status */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_liveliness_changed_status (
    ::DDS::LivelinessChangedStatus & /* status */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_requested_deadline_missed_status (
    ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_requested_incompatible_qos_status (
    ::DDS::RequestedIncompatibleQosStatus & /* status */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_subscription_matched_status (
    ::DDS::SubscriptionMatchedStatus & /* status */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_sample_lost_status (
    ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::wait_for_historical_data (
    const ::DDS::Duration_t & /* max_wait */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_matched_publications (
    ::DDS::InstanceHandleSeq & /* publication_handles */)
  {
    /* Your code here. */
    return 0;
  }

  ::DDS::ReturnCode_t
  DataReader_exec_i::get_matched_publication_data (
    ::DDS::PublicationBuiltinTopicData & /* publication_data */,
    ::DDS::InstanceHandle_t /* publication_handle */)
  {
    /* Your code here. */
    return 0;
  }

  //============================================================
  // Component Executor Implementation Class: Hello_receiver_Connector_exec_i
  //============================================================

  Hello_receiver_Connector_exec_i::Hello_receiver_Connector_exec_i (void)
    : dds_configured_ (false)
  {
  }

  Hello_receiver_Connector_exec_i::~Hello_receiver_Connector_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes.

  // Port operations.

  ::CCM_DDS::CCM_string_Reader_ptr
  Hello_receiver_Connector_exec_i::get_receiver_data (void)
  {
    this->configure_dds ();
    /* Your code here. */
    // @todo
    return ::CCM_DDS::CCM_string_Reader::_nil ();
  }

  ::CCM_DDS::CCM_ListenerControl_ptr
  Hello_receiver_Connector_exec_i::get_receiver_control (void)
  {
    this->configure_dds ();
//    return ::DDS::CCM_DataWriter::_duplicate (this->dw_.in ());

    /* Your code here. */
    // @todo
    return ::CCM_DDS::CCM_ListenerControl::_nil ();
  }

  ::DDS::CCM_DataReader_ptr
  Hello_receiver_Connector_exec_i::get_receiver_dds_entity (void)
  {
    this->configure_dds ();
    /* Your code here. */
    // @todo
    return ::DDS::CCM_DataReader::_nil ();
  }

  // Operations from Components::SessionComponent.

  void
  Hello_receiver_Connector_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_DDS::CCM_Hello_receiver_Connector_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Hello_receiver_Connector_exec_i::configuration_complete (void)
  {
    this->configure_dds ();
    /* Your code here. */
  }

  void
  Hello_receiver_Connector_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Hello_receiver_Connector_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Hello_receiver_Connector_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  void
  Hello_receiver_Connector_exec_i::configure_dds (void)
  {
    if (this->dds_configured_)
      return;

    try
      {
        //NDDSConfigLogger::get_instance()->set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API,
        //                                                          NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL );

        /*dpf_ = new CIAO::DDS4CCM::RTI::RTI_DomainParticipantFactory_i ();
        ::DDS::DomainParticipantQos qos;
        dp_ = dpf_->create_participant (0, qos, 0, 0);

        ::DDS::TopicQos tqos;
        t_ = dp_->create_topic ("Hello, World",
                                CIAO::DDS4CCM::RTI::String_Traits::type_support::get_type_name (),
                                tqos,
                                0,
                                DDS_STATUS_MASK_NONE);

        ::DDS::SubscriberQos sqos;
        sub_ = dp_->create_subscriber (sqos,
                                      0,
                                      0);

        ::DDS::DataReaderQos drqos;
        DDS::DataReader_var drv_tmp = sub_->create_datareader (t_.in (),
                                                               drqos,
                                                               &listener_,
                                                               0);

        dr_ = DDS::CCM_DataReader::_narrow (drv_tmp);*/
        
            /* Create the domain participant on domain ID 0 */
    DDSDomainParticipant *participant = DDSDomainParticipantFactory::get_instance()->
                       create_participant(
                        0,                              /* Domain ID */
                        DDS_PARTICIPANT_QOS_DEFAULT,    /* QoS */
                        0,                           /* Listener */
                        DDS_STATUS_MASK_NONE);
    if (!participant) {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unable to create domain participant.\n")));
    }

    /* Create the topic "Hello, World" for the String type */
    DDSTopic *topic = participant->create_topic(
                        "Hello, World",                        /* Topic name*/
                        DDSStringTypeSupport::get_type_name(), /* Type name */
                        DDS_TOPIC_QOS_DEFAULT,                 /* Topic QoS */
                        0,                                  /* Listener  */
                        DDS_STATUS_MASK_NONE);
    if (!topic) {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unable to create topic.\n")));
    }

    /* Create the data writer using the default publisher */
    DDSDataReader *data_reader = participant->create_datareader(
                        topic,
                        DDS_DATAREADER_QOS_DEFAULT,    /* QoS */
                        &listener_,                      /* Listener */
                        DDS_DATA_AVAILABLE_STATUS);
    if (!data_reader) {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unable to create data reader.\n")));
    }

printf ("setup done\n");        
      }
    catch (const CORBA::Exception &ex)
      {
        CIAO_ERROR ((LM_ERROR, CLINFO "Hello_receiver_Connector_exec_i::configure_dds - "
                     "Caught CORBA exception %C\n",
                     ex._info ().c_str ()));
      }
    catch (...)
      {
        CIAO_ERROR ((LM_ERROR, CLINFO "Hello_receiver_Connector_exec_i::configure_dds - "
                     "Error: caught unknown C++ exception while configuring DDS\n"));
      }

    this->dds_configured_ = true;
  }

  extern "C" HELLO_RECEIVER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_DDS_Hello_receiver_Connector_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_RETURN (
      retval,
      Hello_receiver_Connector_exec_i,
      ::Components::EnterpriseComponent::_nil ());

    return retval;
  }
}

namespace CIAO_Hello_DDS_Hello_receiver_Connector_Impl
{
  //============================================================
  // Home Executor Implementation Class: ReceiverConnectorHome_exec_i
  //============================================================

  ReceiverConnectorHome_exec_i::ReceiverConnectorHome_exec_i (void)
  {
  }

  ReceiverConnectorHome_exec_i::~ReceiverConnectorHome_exec_i (void)
  {
  }

  // All operations and attributes.

  // Factory operations.

  // Finder operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  ReceiverConnectorHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      Hello_receiver_Connector_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" HELLO_RECEIVER_CONNECTOR_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_DDS_ReceiverConnectorHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      ReceiverConnectorHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

