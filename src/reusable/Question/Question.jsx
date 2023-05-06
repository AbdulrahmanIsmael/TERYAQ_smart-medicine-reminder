import Accordion from '@mui/material/Accordion';
import AccordionSummary from '@mui/material/AccordionSummary';
import AccordionDetails from '@mui/material/AccordionDetails';
import Typography from '@mui/material/Typography';
import ExpandMoreIcon from '@mui/icons-material/ExpandMore';
import { Divider } from '@mui/material';

// eslint-disable-next-line react/prop-types
const Question = ({ question, answer }) => {
  return (
    <div>
      <Accordion m={5}>
        <AccordionSummary
          expandIcon={<ExpandMoreIcon />}
          aria-controls='panel1a-content'
          id='panel1a-header'
        >
          <Typography variant='h6'>{question}</Typography>
        </AccordionSummary>
        <Divider />
        <AccordionDetails className='answer'>
          <Typography>{answer} </Typography>
        </AccordionDetails>
      </Accordion>
      <Divider />
    </div>
  );
};

export default Question;
